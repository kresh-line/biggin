#include <stdio.h>

int main() {
    int num, max, min;
    int i = 0;
    
    printf("Jepni numrat (0 për të ndaluar): ");
    scanf("%d", &num);
    
    // Nëse nuk futen numra
    if (num == 0) {
        printf("Nuk futët asnjë numër!\n");
        return 0;
    }
    
    // Inicializimi me numrin e parë
    max = num;
    min = num;
    i = 1;
    
    // Lexo numrat e mbetur derisa të futet 0
    while (1) {
        scanf("%d", &num);
        
        if (num == 0) {
            break;  // Ndalo kur futet 0
        }
        
        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
        i++;
    }
    
    printf("\nMë i madhi: %d\n", max);
    printf("Më i vogli: %d\n", min);
    
    return 0;
}
