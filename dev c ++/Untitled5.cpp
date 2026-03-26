#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 100
#define N 100

int main() {
    int array[M][N];
    int i, j, m, n;

    srand(time(NULL));

    printf("Number of rows: ");
    scanf("%d", &m);
    printf("Number of columns: ");
    scanf("%d", &n);

    if (m == n) {
        printf("\nReading the matrix...\n");
        for (i = 0; i < m;  ++i)
            for (j = 0; j < n; ++j)
                array[i][j]=rand()%100;

        printf("\nThe given matrix is:\n");
        for (i = 0; i < m; ++i) { 
            for (j = 0; j < n; ++j)
                printf("%d",array[i][j]);
                printf("\n");
        
        }  
        
        for (i = 0; i < m; ++i) { 
            int sum = 0;
        
            for (j = 0; j < n; ++j)
               sum +=array[i][j];
                printf("line %d, sum %d\n", i, sum);}
                
                
         for (i = 0; i < n; ++j) { 
             int sum=0;
            for (i = 0; i < m; ++i)
                sum +=array[i][j];
                
            printf("colume %d, Sum %d\n", j, sum);}
    
    for (i = 0; i < m; ++i) { 
            int sum = 0;
        
            for (j = 0; j < n; ++j)
            if(i==j)
               sum +=array[i][j];
                printf("sum diag = , %d\n", sum);
    
           } } else {
        printf("\nMatrix is not square! (m != n)\n");
    }
system("pause");

}
