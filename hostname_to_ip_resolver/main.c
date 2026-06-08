#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    struct addrinfo hints; // defining struct for storing socket addresses and connection configs
    struct addrinfo *res; // this stores the memory address of a future struct addrinfo
    
    while(1) {
        char hostBuffer[100];
        
        printf("Find IP address of: ");
        fgets(hostBuffer, sizeof(hostBuffer), stdin);
        hostBuffer[strcspn(hostBuffer, "\n")] = '\0';
        
        memset(&hints, 0, sizeof(hints)); //first we have to clear any garbage memory the OS might allocate to the struct
        
        hints.ai_family = AF_INET6; // what kind of IP address do i want to send and receive? Best left as unspecified
        hints.ai_socktype = SOCK_STREAM; // how do i want the data to be sent? stream socket or datagram?
        
        // this is where we get the actual address information
        // we use getaddrinfo to get information about an IP address.
        
        // the first argument "google.com" is the hostname and it quereies the Domain Name Service and to find the IP address which lives on that port
        // the next argument "80" is the port. Port 80 is the port for all unencrypted web traffic. 443 is for encrypted traffic (HTTPS). We are not actually sending any data here. Just a database lookup.
        // &hints is the memory address of the addrinfo struct. hints already exists in the memory because we initialised it earlier. All getaddrinfo is doing is reading the "hints" that we gave it and using it as criteria for its DNS search.
        
        // *res is a pointer variable. right now it probably holds garbage but it is going to hold the memory address of a addrinfo struct when we pass it to getaddrinfo. we pass &res and not *res because we want to pass the function the memory address of where it can write the memory address of the addrinfo struct it gets from the lookup. *res would be dereferencing the struct addrinfo and would probably return the garbage data.
        //it has to be done like this because functions in c can only return one thing, being whether the call was successful or not which is why the function is set to int status.
        
        int status = getaddrinfo(hostBuffer, NULL , &hints, &res);
        
        if (status != 0) {
            printf("\n Couldn't look up IP address for %s", hostBuffer);
            return 1;
        }
        
        char ipv6_string[INET6_ADDRSTRLEN];
        
        struct sockaddr_in6* ipv6 =  (struct sockaddr_in6* )(res->ai_addr);
        inet_ntop(AF_INET6, &(ipv6->sin6_addr), ipv6_string, INET6_ADDRSTRLEN);
        
        printf("This is the ipv6 address for %s : %s\n", hostBuffer, ipv6_string);
        
        freeaddrinfo(res);
        
    }
    
    return 0;
    
}

