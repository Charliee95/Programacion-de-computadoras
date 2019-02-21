//PROCEDIMIENTO RECURSIVO QUE MUESTRE EN PANTALLA TODOS LOS NUMEROS QUE ESTAN ENTRE UN ENTERO Y OTRO DE FORMA ASCENDENTE
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1, numero2, i;

    printf("Ingrese el primer numero: ");
    scanf("%d",&numero1);
    printf("Ingrese el segundo numero: ");
    scanf("%d",&numero2);
    i=numero1;

    /*if(numero1 < numero2){
        i=numero1;
    }
    else{
        i=numero2;
    }*/

    mostrarNumeros(numero1, numero2, i);


    return 0;
}

void mostrarNumeros(int n1, int n2, int cont) {
    if(n1 <= n2) {
        if(cont >= n1 && cont <= n2) {
            printf(", %d",cont);
            mostrarNumeros(n1, n2, cont + 1);
        }
    }
    else {
        if(cont >=n2 && cont <= n1) {
            printf(", %d",cont);
            mostrarNumeros(n1, n2, cont - 1);
        }
    }
}
