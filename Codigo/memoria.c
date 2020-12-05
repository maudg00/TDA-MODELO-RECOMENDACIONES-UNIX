/*#include "memoria.h"


float **memoriaMatriz(int largo, int ancho){
   float **matriz = (float**) malloc(sizeof(float*)*largo);
   for (int i=0;i< largo; i++){
      *(matriz+i) = malloc(sizeof(float)*ancho);
   }
   return matriz;
}

void memoriaDMatriz(int largo, int ancho, float **matriz){
  for(int i = 0; i < largo; i++){
      free(matriz[i]);
  }
  free (matriz);
}*/
