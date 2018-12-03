#include <stdio.h>
void input_nums(int *lotto_nums);
void print_nums(int *lotto_nums);

int main(int argc, char const *argv[])
{
    int lotto_nums[6];
    input_nums(lotto_nums);
    print_nums(lotto_nums);
    
    return 0;
}
void input_nums(int *lotto_nums){
    scanf("%d",&lotto_nums[0]);
    for(int i=1;i<6;i++){
        for(int j=1;j<i+1;j++){
            scanf("%d",&lotto_nums[i]);
            if(lotto_nums[i] == lotto_nums[j]){
                printf("same number\n");
                i--;
            }
        }
    }
}
void print_nums(int *lotto_nums){
    for(int i =0;i<6;i++){
        printf("%d ",lotto_nums[i]);
    }
}
