#include <sys/types.h>
#include <sys/sockets.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        printf("Missing IPv4 Address or Port Number");
        return 1;
    }

    struct addrinfo hints;
    struct addrinfo *res;

    memset(&hints, 0, sizeof hints);

    hints.ai_family = AF_INET;
    hints.ai_sock_type = SOCK_STREAM;

    int status = getaddrinfo(argv[1], argv[2], &hints, &res);

    if (status != 0)
    {
        printf("Error looking up address");
    }

    int sockfd = socket(res->ai_family, res->ai_addr, res->ai_addrlen);
}
