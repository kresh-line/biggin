#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 5
#define N 5

main () {
int pinA[M][N], pinB[M][N], pinC[M][N];
int line=0, column=0, n = 0, m;


for (n=0; n <= M; n++)
for (m=0; m <= N; m++) {
    
    
pinA[n] [m] = 0;
pinB[n] [m] = 0;
pinC[n] [m] = 0;
}
pinA [0] [0] = 5;
pinA [2] [4] = 87;
pinA [3] [2] = 44;

pinB [0] [0] = 54;
pinB [2] [4] = 11;
pinB [3] [2] = 85;
pinB [4] [2] = 5;
pinB [2] [2] = 87;

for (n=0; n <= M; n++)
for(m=0; m <= N; m++) {
pinC [n] [m] = pinA[n][m]+pinB[n][m];
}
for (n=0; n <= M; n++) {
for (m=0; m <= N; m++) {
printf("%d\t", pinC[n][m]);
}
printf("\n");

}
system("pause");
}


