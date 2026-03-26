#include <stdio.h>
#include <stdlib.h>
#define N 5
main()
{


int x[N], y[N], *p1, *p2; // kanete sto spiti me poiner ...
int i,sum=0;


printf("Enter arraly elements:\n");
for(i=0;i<N;i++) //������� �� �������
scanf("%d, %d",&x[i], &y[i]);

printf("You have entered:\n");
for(i=0;i<N;i++) //������ �� �������
printf("%d, %d\n",x[i], y[i]);
      

for(i=0;i<N;i++) {   // ������� �� ������� (pointer)
sum = sum + (x[i]*y[i]);
// ���������  *ptr: �� ����������� ��� ����� ��� ��������� ��� ������� � ptr


}

printf("\n The sum of array elements is %d\n",sum);

system("pause");
}
