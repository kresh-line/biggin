#include <stdio.h>
#include <stdlib.h>



void printline(int line)
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
void printTree(void){
int i;
for (i=1; i<=5; i++){
    printline(i);
    printf("\n");
}
}
void printOrthogonio(int lines, int columns) {
int i;
for (i=1; i <= lines; i++)
printline(columns);
}
main ()
{
int i;

printCube();
printTree();
printOrthogonio(6,4);

printf ("\n");


system("PAUSE");
}

