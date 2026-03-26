
   #include <stdio.h>
int main () { 
    int N =5, line, stars;
    printf("DOSE N\n");
    scanf( "%d", &N);
    for(line=0; line<N; line++) { for(stars=0; stars<=line; stars++){
        printf ("*");}
    printf("\n");
    }
}
    
