//
//  memoria.h
//
//
//  Created by Equipo 2 on 8/oct/2020
//

#ifndef memoria_h
#define memoria_h

/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

/* Constants declarations. */

/* Set EXTERN macro: */

#ifndef memoria_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif


/* Global variables declarations. */


/* Function prototypes. */
/*
  La funcion memoriaMatriz aloja dinamicamente la matriz de largo*ancho
  @params int largo, int ancho,
  return float **matriz
*/


EXTERN float **memoriaMatriz(int largo, int ancho);
/*
  La funcion memoriaDMatriz dealoja dinámicamente la matriz de largo*ancho
  @params int largo, int ancho, float *matriz[ancho]
  return
*/
EXTERN void memoriaDMatriz(int largo, int ancho, float **matriz);

#undef memoria_IMPORT
#undef EXTERN
#endif /* memoria_h */
