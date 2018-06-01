#include<stdio.h>
#include<string.h>
int main(){
    char input_Arr[100];
    int length = 0;
    int i=0;
    scanf("%[^\n]",input_Arr);
    printf("%s",input_Arr);
    
    printf("Array length is %ld!!\n",strlen(input_Arr));

    length = strlen(input_Arr);
    for(i=length;i>=0;i--){
        printf("%c",input_Arr[i]);
    }

    return 0;
}