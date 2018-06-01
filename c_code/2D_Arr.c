#include <stdio.h>

int main(int argc,char *argv[]){
    // char *str = "Hong Gil Dong";
    // int i = 0;
    // for(i=3; i<7; i++){
    //     printf("%c ",*(str+i));
    // }
//----------------------------------------
    char *str = "Good morning!";
    int i=0;
    int list[5] = {0,};
    for(i=0;i<5;i++){
        printf("%d 번째 숫자 입력:",i);
        scanf("%d",&list[i]);
    }
    
    for(i=0;i<5;i++){
        printf("%c ",*(str+list[i]));
    }
    return 0;
}