#include<stdio.h>

int main(int argc,char *argv[]){

    int S = 1, O = 0, T = 1;
    int i = 0;
    int req,res = 0;
    for(S=1;S<10;S++){
        for(O=0;O < 10;O++){
            for(T=1;T<10;T++){
                req = ((100*S+10*O+T)-(10*S+O));
                res = 10*T+T;
                if(req == res){
                    printf("%d %d %d",S,O,T);
                }
            }
        }
    }
    return 0;
}