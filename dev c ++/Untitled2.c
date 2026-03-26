#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
int main() {
int i, temp, pin[N];
srand(time(NULL)); 
for (i=0; i<N; i++)
pin[i] =1 + rand() % 100; 
printf("\nO pinakas: \n"); 
for (i=0; i<N; i++)
printf("%d\n", pin[i]);

for (i=0; i<N/2; i++) {
temp= pin[i];
pin[i]= pin[N-i-1];
pin[N-i-1]= temp;
}
printf("\nO antistrofos pinakas: \n");
for (i=0; i<N; i++)
printf("%d\n", pin[i]);
 getchar();





}
