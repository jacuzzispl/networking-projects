# C Hostname to IP Resolver!

A simple tool written to C that resolves hostnames like apple.com or google.com into their corresponding IPv4 addresses.

I wrote it as an experiment to better understand the getaddrinfo() functions and how more generally the IP Layer works. I am using Beej's guide to Networking.

If you want to run the code yourself:

- clone the repository
- compile the source file
  - (on Mac this is something like gcc main.c -o main in your terminal)
- run the executable in your terminal ( run ./main)

## Example Output

```
Find IP address of:
google.com
The ip address for google.com is 142.250.179.238
```

## What I learned

-
