#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *massage);
int main(int argc, char const *argv[])
{
    int serv_sock;
    int clint_sock;

    struct sockaddr_in serv_addr; // server addr (use to binding)
    struct sockaddr_in clnt_addr; //clint addr
    socklen_t clnt_addr_size ;

    char massage[]= "Hello, World!";

    if(argc != 2){
        printf("Usage : %s <port>", argv[0]);
        exit(1);
    }
    serv_sock= socket(PF_INET,SOCK_STREAM,0);
    if(serv_sock == -1){
        error_handling("socket() error");
    }
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))==-1){
        error_handling("binde() error");
    }
    if(listen(serv_sock,5)==-1) error_handling("listen() error");
    clnt_addr_size = sizeof(clnt_addr);
    clint_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    
    write(clint_sock, massage, 4);
    sleep(5);
    write(clint_sock, massage+4, 4);
    sleep(5);
    write(clint_sock, massage+8, 4);
    sleep(5);
    write(clint_sock, massage+12, sizeof(massage)-12);

    close(clint_sock);
    close(serv_sock);
    return 0;
}
void error_handling(char *massage){
    fputs(massage,stderr);
    fputc('\n',stderr);
    exit(1);
}