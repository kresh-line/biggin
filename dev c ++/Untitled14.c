#include <stdio.h>

void printLiine(int line)
{ int y;
for (y=1;y<=line; y++)
printf ("%c",'*');
}
void printCube(void)
{



int i,y;
for (i=1; i<=5; i++){
for (y=1; y<=5; y++)
printf("%c",'*');
printf("\n");
}
}
int main ()
{
int i;

for (i=0; i<10; i++){
    
printCube();
printf ("\n");
}



system("PAUSE");
}

