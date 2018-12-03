#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
void error_handling(char *massage);
int main(void)
{
    int fd;
    char buff[10];

    fd=open("abc.txt",O_RDONLY);
    if(fd ==-1) 
        error_handling("open() error");
    printf("file descriptor: %d\n",fd);

    if(read(fd,buff,sizeof(buff))==-1) 
        error_handling("write() error");
    
    printf("%ld\n\n",sizeof(buff));
    printf("%s\n",buff);

    close(fd);
    return 0;
}

void error_handling(char *massage){
    fputs(massage,stderr);
    fputc('\n',stderr);
    exit(1);
}