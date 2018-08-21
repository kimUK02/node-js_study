
#include <stdlib.h>
#include <unistd.h>

int main(){

  char buf2[10];
  char buf[10];

	  printf("It can be overflow : ");
  fgets(buf,40,0);

  if ( strncmp(buf2, "go", 2) == 0 )
   {
        printf("Good Skill!\n");
        setreuid( 3010, 3010 );
        system("/bin/bash");
   }

}

