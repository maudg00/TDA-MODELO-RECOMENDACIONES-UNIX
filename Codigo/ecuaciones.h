//
//  ecuaciones.h
//  TDA
//
//  Created by Equipo 2 on 29/11/20.
//

#ifndef ecuaciones_h
#define ecuaciones_h

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

/* Set EXTERN macro: */

#ifndef ecuaciones_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

EXTERN void ecuacionesCopy(float **matriz, float *arreglo, int tam);
/*
  Deep Copy entre arreglo y primer fila de la mariz (columnas=FEATURES).
  @params float *matriz[ancho], float *arreglo
  @return
*/

EXTERN void ecuacionesOrdenar(int largo, float **matriz);
/*
  Ordena las filas de la matriz en orden descendente con respecto al valor
  de la segunda columna de la matriz.
  @params int largo, float *matriz[largo]
  @return
*/

EXTERN void ecuacionesRecomendacion(int ancho, int features, float *arreglo,
float *arreglo2, float **matriz);
/*
  EcuacionesRecomendación hace el producto punto entre nuestro arreglo y
  la matriz y guarda los valores en arreglo2
  @params int ancho, int features, float *arreglo,
  float *arreglo2, float *matriz[ancho]
  @return
*/
EXTERN void ecuacionesRandom(int largo, int ancho, float **matriz);
/*
    Asigna valores aleatorios entre 0 y 1 a toda la matriz.
    @params int largo, int ancho, float **matrix
    @return
 */

EXTERN void ecuacionesPP(int largo, int ancho, int features, float **matriz1,
  float **matriz2, float **matrizFinal);
/*
    Hace el producto punto entre matriz1 y matriz2 y asigna los valores a la matrizFinal
    @params int largo, int ancho, float **matriz1, float **matriz2, float **matrizFinal
    @return
 */

EXTERN void ecuacionesCero(int largo, int ancho, float **matriz);
/*
    Hace 0 todos los valores dentro de la matriz
    @params float **matriz
    @return
 */

EXTERN float ecuacionesError(int largo, int ancho, float **matrizEntrenamiento, float **matrizRandom);
/*
    Asigna a la matrizRandom el error entre las otras 2 matrices
    @params int largo, int ancho, float **matrizEntrenamiento, float **matrizRandom
    @return error
 */

EXTERN void ecuacionesCorregir(int largo, int ancho, int features,
  float **matriz1, float **matriz2,
  float **matrizError, float n);
/*
    Actualizar matriz1 con stochastic gradient descent
    @params int largo, int ancho, float **matriz1, float **matriz2, float **matrizError
    @return
 */

EXTERN void ecuacionesStochasticGradientDescent(int largo, int ancho, int features,
    int maxEpocs, float* errores, float** matriz1, float** matriz2,
    float** matriz3, float** matriz4);
 /*
  La función de ecuacionesStochasticGradientDescent manda a llamar a las
  respetivas funciones del módulo para que este puede hacer el modelo predictivo
  asociado al SGD.
  @params int largo, int ancho, int features,
  int maxEpocs,float *errores, float *matriz1[features], float *matriz2[features],
  float *matriz3[ancho], float *matriz4[ancho]
  @return
 */

#endif /* ecuaciones_h */
