#include <stdio.h>
#include <arpa/inet.h>
int main(int argc, char const *argv[])
{
    unsigned short host_port = 0x1234;
    unsigned short net_port;
    unsigned long host_addr = 0x1235678;
    unsigned long net_addr;

    net_port = htons(host_port);
    net_addr = htonl(host_addr);

    printf("Host odered Port : %#x \n",host_port);
    printf("Network ordered Port : %#x \n",net_port);
    printf("Host ordered Address : %#lx\n",host_addr);
    printf("Network ordered Address : %#lx \n",net_addr);
    return 0;
}
