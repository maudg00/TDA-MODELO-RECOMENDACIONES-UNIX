//
//  pipes.h
//
//
//  Created by Mauricio de Garay, Bernardo García and Fernando Tapia on 29/09/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#ifndef pipes_h
#define pipes_h
#ifndef pipes_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif


/* Función del módulo. */
/*
* El módulo pipes se encarga de abrir y escribir el archivo csv con los resultados, y además de establecer la conexión con GNUPlot y graficar este archivo.
*
*
*/


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
EXTERN FILE* pipesOpenFile(char *archivo);

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
EXTERN void pipesCloseFile(FILE *data);

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
void pipesWriteFile(int rows, float RespuestaResorte[], float TiempoDiscreto[], FILE * fpointer);

/*
* La función pipesNewFile escribe nuevo archivo
*/
EXTERN FILE* pipesWriteNewFile(char *archivo);

/*
* La función openGnuPlot  se encarga de retornar un pipepointer que tenga una conexión establecida con GNUPlot.
*
*
* @params
*
* @returns
       FILE * gnupointer
*/
EXTERN FILE * pipesOpenGnuPlot();

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
EXTERN void pipesGraphGnuPlot(FILE * gnupointer, char NombreArch[]);

EXTERN void pipesWritePlot(FILE *especial, float *arreglo, int size);
/*
* La función pipesObtenerValores se encarga de recibir de un archivo los datos y guardarlos en arreglo
*
*
* @params
    arreglo, archivo
*
* @returns
*/
EXTERN void pipesObtenerValores(float *arreglo, FILE *archivo);

EXTERN void pipesWrite(FILE *archivo, float error[], int tam);
#undef pipes_IMPORT
#undef EXTERN
#endif
