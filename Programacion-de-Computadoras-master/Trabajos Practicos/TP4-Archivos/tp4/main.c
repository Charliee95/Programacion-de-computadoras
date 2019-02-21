#include <stdio.h>
#include <stdlib.h>

#include "equipo.h"
#include "jugador.h"


Equipo vectorDeEquipos[100];


//Funciones hechas en el main
Equipo crearEquipoDesdeChar(char aux[100]);
void cargarVectorDeEquipos();
void mostrarEquipos();
Jugador crearJugadorDesdeChar(char aux[100]);

void cargarEquipo(char nombre[20],int hinchas,int codigo);
void cargarJugador(char nombre[20],char apellido[20],int codigo);

int main()
{
    cargarVectorDeEquipos();
    int opcion;
    printf("Bienvenido al sistema \n1)mostrar los equipos con sus jugadores\n2)Agregar equipo\n3)Agregar Jugador\n0)salir.");
    scanf("%d",&opcion);
    switch(opcion){
    case 1:   mostrarEquipos();
        break;
    case 2: system("cls");
            char nombre[20];
            int hinchas;
            int codigo;
            fflush(stdin);
            printf("Nombre del equipo:");
            gets(nombre);
            printf("\nCantidad de hinchas:");
            scanf("%d",&hinchas);
            printf("\nCodigo del equipo:");
            scanf("%d",&codigo);
            cargarEquipo(nombre,hinchas,codigo);
            break;
    case 3: system("cls");
            fflush(stdin);
            char jnombre[20];
            char apellido[20];
            int jcodigo;
            printf("Nombre del jugador:");
            gets(jnombre);
            printf("\nApellido del jugador:");
            gets(apellido);
            printf("\nCodigo del equipo al que pertenece:");
            scanf("%d",&jcodigo);
            cargarJugador(jnombre,apellido,jcodigo);
            break;
   case 0: break;
    }
    return 0;
}












//Funciones: Podrian ponerlas en el TDA si quieren hacerlo aun mejor.


void cargarVectorDeEquipos(){
    FILE * equipo;
    equipo = fopen("equipo.txt", "r");

    //indice para recorrer el vector de eventos
    int i = 0;

    while(!feof(equipo)){




        fflush(stdin);
        char auxLectura[100] = " ";



        fgets(auxLectura, 100, equipo);


        Equipo e = crearEquipoDesdeChar(auxLectura);

        vectorDeEquipos[i] = e;
        i++;

        }


    fclose(equipo);
}






Equipo crearEquipoDesdeChar(char aux[100]){


        int ubicacionPrimerDelimitador = 0;
        int ubicacionSegundoDelimitador = 0;

        char auxNombre[100] = " ";
        char auxCant[100] = " ";
        char auxCod[100] = " ";

        for (int i = 0; i<100; i++){

            if(aux[i]==','){
                    ubicacionPrimerDelimitador = i;
                    i=100;
            }


        }


        for (int i = ubicacionPrimerDelimitador+1; i<100; i++){

            if(aux[i]==','){ ubicacionSegundoDelimitador = i;
            i=100;}

         }




         for (int i = 0; i<ubicacionPrimerDelimitador; i++){
            auxNombre[i] = aux[i];
         }



         int inicioCant = 0;

         for (int i = ubicacionPrimerDelimitador+1; i<ubicacionSegundoDelimitador; i++){

         auxCant[inicioCant] = aux[i];
         inicioCant++;
         }

        int inicioCod = 0;

         for (int i = ubicacionSegundoDelimitador+1; i<100; i++){
            auxCod[inicioCod] = aux[i];
            inicioCod++;
         }



         Equipo e = crearEquipo(auxNombre, atoi(auxCant), atoi(auxCod));


return e;
}


void mostrarEquipos(){


   for (int i = 0; i<100;i++){


        mostrarEquipo(vectorDeEquipos[i]);

    }

}




Jugador crearJugadorDesdeChar(char aux[100]){


        int ubicacionPrimerDelimitador = 0;
        int ubicacionSegundoDelimitador = 0;

        char auxNombre[100] = " ";
        char auxApellido[100] = " ";
        char auxCod[100] = " ";

        for (int i = 0; i<100; i++){

            if(aux[i]==','){
                    ubicacionPrimerDelimitador = i;
                    i=100;
            }


        }


        for (int i = ubicacionPrimerDelimitador+1; i<100; i++){

            if(aux[i]==','){ ubicacionSegundoDelimitador = i;
            i=100;}

         }




         for (int i = 0; i<ubicacionPrimerDelimitador; i++){
            auxNombre[i] = aux[i];
         }



         int inicioCant = 0;

         for (int i = ubicacionPrimerDelimitador+1; i<ubicacionSegundoDelimitador; i++){

         auxApellido[inicioCant] = aux[i];
         inicioCant++;
         }

        int inicioCod = 0;

         for (int i = ubicacionSegundoDelimitador+1; i<100; i++){
            auxCod[inicioCod] = aux[i];
            inicioCod++;
         }



         Jugador j = crearJugador(auxNombre, auxApellido, atoi(auxCod));


return j;
}

void cargarEquipo(char nombre[20],int hinchas,int codigo){
    FILE*e1;
    e1=fopen("equipo.txt","a");
    fprintf(e1,"\n%s,%d,%d",nombre,hinchas,codigo);
    fclose(e1);
}

void cargarJugador(char nombre[20],char apellido[20],int codigo){
    FILE*j1;
    j1=fopen("jugador.txt","a");
    fprintf(j1,"\n%s,%s,%d",nombre,apellido,codigo);
    fclose(j1);
}
