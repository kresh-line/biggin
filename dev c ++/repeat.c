#include <stdio.h>
#include <stdbool.h>
char C;  // καθολική μεταβλητή
void printchar (int m) // Ορισμός πριν την main()
{
    int i;
    for (i=1; i<=m; i++)
        printf ("%c", C);
    printf ("\n");}
 bool filtro (char ch) {if (ch!='*')
return true;
return false;
 }
main ()
{
    int N, i;
    char option;
    do{
    printf("doste character:");
    fflush(stdin);
    scanf("%c", &C);
    
    printf("doste arithmo:");
    fflush(stdin);
    scanf ("%d", &N);
    printchar (N);
    for (i=1; i<=N; i++)
    if (filtro(C)==true)
        printchar (i);
        printf("Repeat?\n");
        fflush(stdin);
        scanf("%c", &option);
} while(option=='y');

system("PAUSE");
}