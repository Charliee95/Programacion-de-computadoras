#include <stdio.h>
#include <stdlib.h>

void recursividad(int mayor,int menor,FILE*archivo2){
    if(mayor!=menor){//el procedimiento imprime hasta que los 2 numeros sean iguales
        printf("%d\n",mayor);//se guarda de la misma manera que se imprime en la consola
        fprintf(archivo2,"%d\n",mayor);
        recursividad(mayor-1,menor,archivo2);
    }
}

int main() // TP1: el programa lee 2 numeros de un txt y guarda los numeros entre estos 2 numeros en otro txt.
{
    FILE*archivo1;//abrimos los archivos
    archivo1=fopen("numeros.txt","r");//en este se encuentran los numeros a leer
    FILE*archivo2;
    archivo2=fopen("archivo.txt","w");//aqui se depositan los numeros de en medio
    char aux[50];
    int numero1;
    int numero2;

    fgets(aux,50,archivo1);
    sscanf(aux,"%d;%d",&numero1,&numero2);//esta instruccion lee un string y separa sus contenidos, el separador es el ";".
    if(numero1>numero2) recursividad(numero1-1,numero2,archivo2); //el if existe para mandar primero el mayor y luego el menor
    else recursividad(numero2-1,numero1,archivo2);
    fclose(archivo1);
    fclose(archivo2);
    return 0;
}
