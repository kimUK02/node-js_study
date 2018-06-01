#include<stdio.h>
int main(){
    char arr[100] = {0,};
    char most = '0',i = 0;

    printf("input :");
    scanf("%s",arr);
    
    for(i=0;arr[i] != '\0'; i++){
        if(arr[i] < arr[i+1]){
            most = arr[i+1];
        }
    }
    printf("%c",most);
    


    return 0;
}