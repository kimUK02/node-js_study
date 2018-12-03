#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char* massage);

int main(int argc, char const *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    char massage[100];
    int str_len;

    if(argc != 3) {
        printf("Usage : %s <IP> <Port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        error_handling("sock() error\n");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family= AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock,(struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1){
        error_handling("connect() error!");
    }
    for(int i = 0;i<100000;i++)
        printf("wait time %d \n",i);
    str_len = read(sock, massage, sizeof(massage)-1);
    if(str_len==-1){
        error_handling("read() error");
    }   

    
    printf("Massage from server: %s \n",massage);
    close(sock);
    return 0;
}
void error_handling(char *massage){
    fputs(massage,stderr);
    fputc('\n',stderr);
    exit(1);
}