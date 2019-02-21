#include <stdio.h>
#include <stdlib.h>

int main()
{
    int largoVector,i;

    printf("Ingrese el largo del vector 1: ");
    scanf("%d",&largoVector);
    int vector1[largoVector], vector2[largoVector];

    for(i=0; i<largoVector; i++) {
        printf("Ingrese los numeros del vector 1: ");
        scanf("%d",&vector1[i]);
    }
    printf("Vector 1:");
    for(i=0; i<largoVector; i++) {
        printf(" %d",vector1[i]);
    }

    for(i=0; i<largoVector; i++) {
        if(vector1[i]%2 == 0) {
            vector2[i] = vector1[i]/2;
        }
        else {
            vector2[i] = vector1[i]*3;
        }
    }
    printf("\nVector 2:");
    for(i=0; i<largoVector; i++){
        printf(" %d",vector2[i]);
    }
    return 0;
}
