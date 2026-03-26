#include <stdio.h>
int main () 
{
int   a=0, b=0, c=0;

printf("Dwste a, b, C:"); 

scanf("%d, %d, %d",&a, &b, &c); 

 printf("diavasa a-%d, b-%d, c=%d\n", a,b,c);
 
printf("Perimeter : %d\n", a+b+c);

 printf("Embadon : %f\n", a*b/2.0);

if(c*c == a*a + b*b)
 printf("Orthogwnio trigwno\n"); 
 else
  printf("Mh orthogwnio trigwno\n"); 
  return ;
}