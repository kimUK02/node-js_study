# random
---
먼저 코드를보면
~~~c
random@ubuntu:~$ cat random.c
#include <stdio.h>

int main(){
	unsigned int random;
	random = rand();	// random value!

	unsigned int key=0;
	scanf("%d", &key);

	if( (key ^ random) == 0xdeadbeef ){
		printf("Good!\n");
		system("/bin/cat flag");
		return 0;
	}

	printf("Wrong, maybe you should try 2^32 cases.\n");
	return 0;
}
~~~

>	random = rand();	// random value!

이부분에서 취약점이 발생한다 그것은 rand()는 값을 정하면 
그값이 변하지 않고

다시실행해도 같은 값이 나온다는 점이다 
그럼 rand()값을 바꿔주면 되겠져?

>(key ^ random) == 0xdeadbeef

이부분에서 key와 random값을 xor 연산으로 비교하는데.

ltrace로 random라이브러리 함수를 추적해보면
~~~
random@ubuntu:~$ ltrace ./random
__libc_start_main(0x4005f4, 1, 0x7ffc23b84fc8, 0x400670 <unfinished ...>
rand(1, 0x7ffc23b84fc8, 0x7ffc23b84fd8, 0)       = 0x6b8b4567
__isoc99_scanf(0x400760, 0x7ffc23b84ed8, 0x7ffc23b84ed8, 0x7ff4dd1220a4
~~~
 **rand(1, 0x7ffc23b84fc8, 0x7ffc23b84fd8, 0)       = 0x6b8b4567**

 따라서 rand()의 값은 0x6b8b4567이다

 key와 0x6b8b4567를 xor 해서 나온 값이  0xdeadbeef이므로

0xdeadbeef 에 random을 xor연산하면 
~~~python
0x6b8b4567^0xdeadbeef
~~~
>3039230856 라는 값이 나온다.

이값을 random 파일에 넣으면 
>(python -c'print "3039230856"')|./random
