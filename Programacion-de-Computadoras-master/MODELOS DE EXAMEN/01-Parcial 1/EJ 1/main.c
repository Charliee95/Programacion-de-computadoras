#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,altura;
    char letra;

    printf("Ingrese la altura de la piramide: ");
    scanf("%d",&altura);
    fflush(stdin);
    printf("Ingrese el caracter: ");
    scanf("%c",&letra);

    for(i=1; i<=altura; i++){
        for(j=1; j<=i;j++) {
            printf("%c",letra);
        }
        printf("\n");
    }
    for(i=altura-1; i>=1; i--) {
        for(j=i ; j>=1; j--) {
            printf("%c",letra);
        }
        printf("\n");
    }
    return 0;
}
