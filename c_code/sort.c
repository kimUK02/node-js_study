#include<stdio.h>
int main(){
    int i,j,temp,min;
    int arr[5] = {50,70,80,90,100};
    for(i=0;i<4;i++){
        min = i;
        for(j =i+1;j<5;j++){
            if(arr[j]< arr[min]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            } //버블
            //// if(arr[j] < arr[min]){
            ////     min = j;
            //// }
            //// temp = arr[i];
            //// arr[i] = arr[min];
            //// arr[min] = temp; //선택
        }
    }
    for(i=0;i<4;i++){
        printf("%d ",arr[i]);
    }
   
    return 0;
}





