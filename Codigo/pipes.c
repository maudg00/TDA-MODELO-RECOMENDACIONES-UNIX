//
//  pipes.c
//
//
//  Created by Mauricio de Garay, Bernardo García and Fernando Tapia on 29/09/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>



/* Function prototypes. */


/*
* La función openFile  se encarga de retornar un filepointer con un nuevo archivo de tipo lectura.
*
*
* @params
*
* @returns
       *FILE fpointer
*/
FILE* pipesOpenFile(char *archivo)
{
    return (fopen(archivo, "rt"));
}

/* Function prototypes. */


/*
* La función openFile  se encarga de retornar un filepointer con un nuevo archivo de tipo lectura.
*
*
* @params
*
* @returns
       *FILE fpointer
*/
FILE* pipesWriteNewFile(char *archivo)
{
    return (fopen(archivo, "wt"));
}

void pipesWritePlot(FILE *especial, float *arreglo, int size){
  int contador=0;
  for(int i=0; i<size; i++){
    contador=contador+1;
    if(arreglo[i]!=arreglo[i+1]){
      fprintf(especial, "%d,%d\n",(int)arreglo[i], contador);
      contador=0;
    }
  }
}

void pipesWrite(FILE *archivo, float error[], int tam){
  int i;

  for(i=0; i<tam; i++){
    fprintf(archivo, "%i,%f\n", i+1, error[i]);
  }
}

/*
* La función closeFile  se encarga de cerrar el filepointer del archivo.
*
*
* @params
    archivo
*
* @returns
       void
*/
void pipesCloseFile(FILE *data)
{
    fclose(data);
}

/*
* La función writeFile  se encarga de escribir un archivo CSV con los arreglos que recibe.
*
*
* @params
    int rows
    float[] RespuestaResorte
    float[] TiempoDiscreto
    FILE * fpointer
*
* @returns
*/



/* La función openGnuPlot  se encarga de retornar un pipepointer que tenga una conexión establecida con GNUPlot.
*
*
* @params
*
* @returns
       FILE * gnupointer
*/
FILE * pipesOpenGnuPlot()
{
    return (popen("gnuplot -persist", "w"));
}

/*
* La función pipesGraphGnuPlot se encarga de graficar en GNUPlot los datos que tenga en un archivo.
*
*
* @params
    gnupointer
    NombreArch
*
* @returns
*/
void pipesGraphGnuPlot(FILE * gnupointer, char NombreArch[])
{
    char cont;
    fprintf(gnupointer,"plot \"%s\" with lines", NombreArch);
    //fflush(gnupointer);
    printf("Presiona enter para continuar...\n");
    scanf("%c", &cont);
    fflush(stdin);
}
