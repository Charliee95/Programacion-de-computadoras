#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector1[20],vector2[20],largoVector=0,i=0,cantpar=0,cantimpar=0,mayor=0,menor=0,mayorPos=0,menorPos=0;

    printf("Ingrese el largo del vector: ");
    scanf ("%d",&largoVector);

    for (i=1; i<=largoVector; i++) {
            printf("Ingrese numeros: ");
            scanf("%d",&vector1[i]);
            if(vector1[i]%2 == 0) {
                cantpar = cantpar + 1;
            }
            else {
                cantimpar = cantimpar + 1;
            }
            if (vector1[i] > mayor) {
                mayor = vector1[i];
                mayorPos = i;
            }
            if (vector1[i] < menor) {
                menor = vector1[i];
                menorPos = i;
            }
    }

    for (i=1; i<=largoVector; i++) {
        vector2[i] = vector1[i];
    }

    printf("El vector1 esta formado por los numeros: ");
    for (i=1; i<=largoVector; i++) {
            printf("%d ",vector1[i]);
    }
    printf("\n");
    printf("El vector 2 esta formado por los numeros: ");
    for (i=largoVector; i>=1; i--) {
            printf("%d ",vector2[i]);
    }

    printf("\n");
    printf("La cantidad de pares del vector1 es: %d \n",cantpar);
    printf("La cantidad de impares del vector1 es: %d \n",cantimpar);
    printf("El numero mayor es: %d y la posicion es: %d \n",mayor,mayorPos);
    printf("El numero menor es: %d y la posicion es: %d",menor,menorPos);


    return 0;
}
