#include <stdio.h>
#include <stdlib.h>
void ejercicioA(){//procedimiento que forma una matriz con las dimensiones ingresadas por teclado y lo llena con un numero random

    FILE*archivo1;
    archivo1=fopen("matriz.txt","w");

    int filas;
    int columnas;

    printf("Elija el tamaño de las filas:");
    scanf("%d",&filas);
    printf("\nElija el tamaño de las columnas");
    scanf("%d",&columnas);
    system("cls");
    printf("La matriz se guardo de la siguiente manera:%d   %d\n",filas,columnas);

    int i,j,aux;
    int matriz[filas-1][columnas-1];

    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            aux=1+rand()%10;
            printf("%d;",aux);
            fprintf(archivo1,"%d;",aux);
        }
        printf("\n");
        fprintf(archivo1,"\n");
    }
}
void ejercicioB(){//Procedimiento que lee los arhivos y los imprimi renglon por renglon
    FILE*archivo1;
    archivo1=fopen("matriz.txt","r");

    char aux[50];
    fgets(aux,50,archivo1);

    do{
        printf("%s",aux);
        fgets(aux,50,archivo1);
    }while(!feof(archivo1));
}
int main(){//Programa que carga vectores en un archivo y luego los lee
    int opcion=0;
    printf("--------------------------------------------------------\nElija el ejercicio:\n(1)Ejercicio a:Crear una matriz del tamanio deseado y guardarlo en un Archivo txt.");
    printf("\n(2)Ejercicio b:Leer una matriz de un txt y mostrarlo\nOtro Nro=salir\n--------------------------------------------------------");
    scanf("%d",&opcion);
    system("cls");
    if(opcion==1)ejercicioA();
    if(opcion==2)ejercicioB();
    return 0;

    }
