#include<stdio.h>
#include<string.h>

int main(){ 
    char input[100] = {'0',};
    int leng = 0;
    char fst = 0;
    int j=0, i = 0;
    scanf("%s", input);
    leng = strlen(input);
    printf("------------------\n");
for(i=0; i<leng; i++){
        fst = input[0];
        for(j=0;j<leng-1;j++){
            input[j] = input[j+1];  
        }
        input[leng-1] = fst;
        printf("%s\n",input);       
    }

    return 0;
}