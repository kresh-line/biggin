#include <stdio.h>
#include <stdlib.h>

 ()
{
char p;
float x, y, result;
int flag=0;
scanf ("%f %c %f", &x, &p, &y);
switch (p) {
case '+': result = x + y; break;
case '-': result = x - y; break;
case '*': result = x * y; break;
case '/': result = x / y; break;
default: printf("Lathos\n");
flag=1;
}
if (flag==0)
printf("%f %c %f = %f\n", x, p, y, result);

system("PAUSE");
}

