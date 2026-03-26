#include <stdio.h>
#include <stdlib.h>
#define N 5
main()
{


int a[N];
int i,sum=0;
int *ptr;

printf("Enter arraly elements:\n");
for(i=0;i<N;i++) //Διαβαζω τη διαταξη
scanf("%d",&a[i]);

printf("You have entered:\n");
for(i=0;i<N;i++) //Τυπονω τη διαταξη
printf("%d\n",a[i]);

ptr=a;       // a=&a[0]

for(i=0;i<N;i++) {   // Δουλευω με δεικτες (pointer)
sum = sum + *ptr;
// θυμηθειτε  *ptr: το περιεχομενο ποθ ειναι στη διευθυνση που δειχνει ο ptr
ptr++;

}

printf("\n The sum of array elements is %d\n",sum);

system("pause");
}
