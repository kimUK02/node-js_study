#include <stdio.h>
void check_same(int *lottonums, int *my_num, int* num);
int main()
{
    int lotto_nums[6] = {4,10,25,30,41,45};
    int my_num[6] = {1,4,7,22,41,43};
    int num = 0;
    check_same(lotto_nums,my_num,&num);
    printf("%d",num);
    return 0;
}
void check_same(int *lottonums, int *my_num, int* num){
    for(int i = 0; i<6; i++){
        for(int j = 0; j < 6; j++){
            if(lottonums[i] == my_num[j]) (*num)++;
        }
    }
}

