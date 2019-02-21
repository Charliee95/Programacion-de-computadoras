#include <stdio.h>
#include <stdlib.h>

int main(){
    int numeros;
    int i=0;
    printf("Ingrese la cantidad de numeros a imprimir: ");
    scanf("%d",&numeros);

    ascendente(numeros,i);

    return 0;
}

void ascendente(int n,int cont){

    if(cont>=0 && cont<n){
        printf(" %d,",cont);
        ascendente(n,cont+1);
    }

}
