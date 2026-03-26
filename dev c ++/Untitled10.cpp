#include <stdio.h>
#include <stdlib.h>
int main()
{
int a[] = {0, 1, 2, 3, 4};
int i, *p;

printf("1: with indices:\n");
/*Print contents of a using array indexing */
for (i = 0; i <= 4; i++)
printf("\t %d", a[i]);
printf("\n");
/*Print contents using pointers */
printf("2: with pointers :\n");
for (p=&a[0];p<=&a[4];p++)
printf("\t %d", *p);
printf("\n");
/*Print contents using pointers, again */
printf("3: with pointers and indices :\n");
p= &a[0];
for (i=0; i<=4;i++)
printf("\t %d", p[i]);
printf("\n");
/*Print contents using pointers, once more */

printf("4: with pointers and counter:\n");
p = a;
for (i = 0;p+i<=a+4;i++)
printf("\t %d", p[i]);
printf("\n");
/*Print contents using pointers */
printf("5: REVERSE pointer and array:\n");
for (p=a+4,i=0;i<=4;i++)
printf("\t %d", p[-i]);
printf("\n");
/*Print contents using pointers */
printf("6: REVERSE just pointer:\n");
for (p=a+4;p>=a;p--)
printf("\t %d", a[p-a]);
printf("\n");
system("pause");
return 0;

}
