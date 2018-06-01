#include <stdio.h>

int main(){
    char ch;
    int tmp;
    double db;
    *&ch = 'P';
    *&tmp = 100;
    *&db = 3.14;
    printf("%d %d %f",ch,tmp,db);

}