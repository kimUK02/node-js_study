#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    int cnt = 0;
    char buff[BUFSIZ];
    int fd = open("./abc.txt",O_RDONLY);
    int fd2 = open("./copy.txt",O_WRONLY|O_CREAT|O_EXCL,0644);
    while((cnt=read(fd,buff,BUFSIZ))>0){
        if(cnt<BUFSIZ){
            write(fd2,buff,cnt);
            break;
        }
        write(fd2,buff,BUFSIZ);
    }

    return 0;
}
