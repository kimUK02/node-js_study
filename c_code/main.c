#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i=0x00000001;
    if(((char *)&i)[0]==1)
        printf("Little Endian.\n");
    else 
        printf("Big Endian.\n");          
    return 0;
}
