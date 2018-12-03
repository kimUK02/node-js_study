#include <stdio.h>

void swap(double *pa, double *pb);
void line_up(double *maxp, double *midp, double *minp);

int main(){
    double min,max,mid;
    printf("input 3: ");
    scanf("%lf %lf %lf",&max,&mid, &min);
    line_up(&max,&mid,&min);
    printf("\n%.1f %.1f %.1f",min,mid,max);
}
void swap(double *pa, double *pb){
    double temp = *pa;
    *pa = *pb;
    *pb = temp;
}
void line_up(double *maxp, double *midp, double *minp){
    if(*maxp < *midp)   swap(maxp, midp);
    if(*midp < *minp)   swap(midp,minp);
    if(*maxp < *minp)   swap(maxp,minp);
}