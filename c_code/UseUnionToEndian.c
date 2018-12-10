#include <stdio.h>

union {
    unsigned int bits32;
    unsigned char bytes[4];
}theValue;

int main(int argc, char const *argv[])
{
    theValue.bits32 = 1;
    if(theValue.bytes[0]==1)
        printf("Little Endian.\n");
    else 
        printf("Big Endian.\n"); 
    return 0;
}
