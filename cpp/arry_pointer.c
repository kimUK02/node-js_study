#include <stdio.h>
void print_graph(int *ps, int size);
int main(int argc, char const *argv[])
{
    int socore[5] = {72,88,95,64,100};
    print_graph(socore,5);
    return 0;
}
void print_graph(int *ps, int size) {
    for(int i =0;i<size;i++){
        printf("(%3d)",*(ps+i));
        for(int j = 0;j<*(ps+i)/5;j++){
            printf("*");
        }
        printf("\n");
    }
}
