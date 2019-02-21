#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void resto(FILE*archivo3,FILE*resto,char aux[50]){
    while(!feof(resto)){//hasata que el archivo mandado no se acabe se seguira imprimiendo
        printf("%s",aux);
        fprintf(archivo3,"%s",aux);
        fgets(aux,50,resto);
    }
}
int main()//ordeno los nombres provenientes de 2 archivos y los pongo ordenados en un 3er archivo
{
    FILE*archivo1; //abro los archivos
    archivo1=fopen("arc1.txt","r");
    FILE*archivo2;
    archivo2=fopen("arc2.txt","r");
    FILE*archivo3;
    archivo3=fopen("arc3.txt","w");

    char aux1[50];//declaro los aux para cada palabra del archivo
    char aux2[50];
    int resultado=0;
    int bandera;//flag que se actica cuando uno de los 2 archivos se termino

    fgets(aux1,50,archivo1);
    fgets(aux2,50,archivo2);
    resultado=strcmp(aux1,aux2);

    while(1){//de manera ordenada se imprime en el 3er archivo hasta que se acabe uno de los dos
        switch(resultado){
        case (-1):  printf("%s",aux1);
                    fprintf(archivo3,"%s",aux1);
                    fgets(aux1,50,archivo1);
                    break;
        case (1):   printf("%s",aux2);
                    fprintf(archivo3,"%s",aux2);
                    fgets(aux2,50,archivo2);
                    break;
        }
        resultado=strcmp(aux1,aux2);
        if(feof(archivo1)){//si uno de los archivos se activa un flag que sale de un bucle con un valor
            bandera=1;
            break;
        }
        if(feof(archivo2)){
            bandera=2;
            break;
        }
    }
    if(bandera==1)resto(archivo3,archivo2,aux2);//dependiendo que archivo termino primero, mando el segundo archivo
    if(bandera==2)resto(archivo3,archivo1,aux1);//a un procedimiento que imprime el resto.
    fclose(archivo1);
    fclose(archivo2);
    fclose(archivo3);

    return 0;
}
