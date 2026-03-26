#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
int main() {
int i, temp, pin[N], pw=1, result=0;
srand(time(NULL)); 
for (i=0; i<N; i++)
pin[i] = rand() % 2; 
printf("\nO pinakas: \n"); 
for (i=0; i<N; i++)
printf("%d\n", pin[i]);

printf("\nDEKADIKOS : \n"); 
for (i=N-1; i>=0; i--)
result += pin[i] * pw;
pw = pw * 2;
printf(" dekadikos = %d\n", result);
 system("pause");
 return 0;

}
