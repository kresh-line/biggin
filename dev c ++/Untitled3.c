#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 100
#define N 100

int main() {
 
char c;
char pinakas [M][N];
int line=0, column=0, n=0;
while( (c=getchar ( )) != '\n') {
if(c == ' ') { 
pinakas[line][column] = '\0';
line++;
column=0;
}

else{
pinakas [line][column] = c;
column++;
pinakas [line][column] = '\0';
}

}

for (n=0; n<=line; n++)
printf ("%s\n", pinakas [n]);

system ("pause");

}

