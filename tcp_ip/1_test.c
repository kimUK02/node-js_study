#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc ==2){
        fputs("worng option\n",stderr);
        exit(1);
    }
    printf("how many options: %d \n",argc-1);
    for(int i = 1; i<argc;i++){
        printf("argv[%d] = %s\n",i , argv[i]);
    }
    printf("Result: %d",atoi(argv[1])+atoi(argv[2]));
    return 0;
}
