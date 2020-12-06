//
//  ecuaciones.c
//  TDA
//
//  Created by Equipo 2 on 29/11/20.
//

#include "ecuaciones.h"
#include "structs.h"
void ecuacionesCopy(float **matriz, float *arreglo, int tam){
  for(int i=0; i<tam; i++){
    matriz[0][i]=arreglo[i];
  }
}

void ecuacionesOrdenar(int largo, float **matriz){
  int j=0;
  float *temp=NULL;
  for(int i=0; i<largo-1; i++){
    for(int j=i+1; j<largo; j++){
      if(matriz[i][1]<matriz[j][1]){
        temp=matriz[i];
        matriz[i]=matriz[j];
        matriz[j]=temp;
      }
    }
  }
}

void ecuacionesRecomendacion(int ancho, int features, float *arreglo,
float *arreglo2, float **matriz){
  
  for(int j=0; j<ancho; j++){
    arreglo2[j] = 0;
      for(int z=0; z<features; z++){
    
          arreglo2[j]=arreglo2[j]+(arreglo[z]*matriz[j][z]);
      }
  }
}

void ecuacionesRandom(int largo, int ancho, float **matriz){
    //srand(time(NULL));
    for(int i=0;i<largo;i++){
        for(int j=0; j<ancho; j++){
            //matriz[i][j]=(rand()%100)/100;
            matriz[0][j]=(float)0.05;
	    
        }

    }
}

void ecuacionesPP(int largo, int ancho, int features, float **matriz1,
  float **matriz2, float **matrizFinal){
    for(int i=0; i<largo; i++){
        for(int j=0; j<ancho; j++){
            for(int z=0; z<features; z++){
	      *(*(matrizFinal+i) + j)=(*(*(matrizFinal+i) + j))+(*(*(matriz1+i) + z)*(*(*(matriz2+j) + z)));
	      *(*(matrizFinal+i) + j)/=(float)ancho;
	  
            }
        }
    }
}

void ecuacionesCero(int largo, int ancho, float **matriz){
    for(int i=0; i<largo; i++){
        for(int j=0; j<ancho; j++){
            *(*(matriz+i) + j)=0;
        }
    }
}

float ecuacionesError(int largo, int ancho, float **matrizEntrenamiento, float **matrizRandom){
    double error=0;
    for(int i=0; i<largo; i++){
        for(int j=0; j<ancho; j++){
          if(*(*(matrizEntrenamiento+i) + j)!=0){
            *(*(matrizRandom+i) + j)=(*(*(matrizEntrenamiento+i) + j))-(*(*(matrizRandom+i) + j));
            error=error+(*(*(matrizRandom+i) + j));
          }
          else{
            *(*(matrizRandom+i) + j)=0;
          }
          //printf("%f ", matrizRandom[i][j]);
        }
        //printf("\n");
    }
    if(error<0)
      error=sqrt(error*error);
    long denominador = largo * ancho;
    float resultado = ((float)error) / (denominador);
    return resultado;
}

void ecuacionesCorregir(int largo, int ancho, int features,
  float **matriz1, float **matriz2,
  float **matrizError, float n){
    for (int i=0; i<largo; i++){
        for(int j=0; j<ancho; j++){
          if(matrizError[i][j]!=0){
            for(int z=0; z<features; z++){
              *(*(matriz1+i) + z)=*(*(matriz1+i) + z)+(*(*(matrizError+i) + j)*
              n*(*(*(matriz2+j) + z)));
	      }
            }
          }
    }
}

/*
  Función StochasticGradientDescent que usa lo de arriba
*/
void ecuacionesStochasticGradientDescent(int largo, int ancho, int features,
int maxEpocs,float *errores, float **matriz1, float **matriz2,
float **matriz3, float **matriz4){

  int j;  
float error=1;
 float errorMax=(float)0.0005, errorMin=0;
float n=(float)0.01;
//PASO 1: Generar de forma aleatoria el contenido de nuestra  matriz
  ecuacionesRandom(largo, features, matriz1);
 
//PASO 2: Inicializar en cero toda la matriz a usar en el producto punto
  //ecuacionesCero(largo, ancho, matriz3);

//PASO 3: Generar el producto punto entre matriz1 y matriz2 y guardarlo en
// la matriz3
  for(int i=0; i<100000; i++){
    ecuacionesCero(largo, ancho, matriz3);
    ecuacionesPP(largo, ancho, features, matriz1, matriz2, matriz3);
  //PASO 4: Obtenemos el error absoluto entre matriz4 y matriz3 (entrenamiento)

    if(i>=maxEpocs){
      break;
    }
    
    error=ecuacionesError(largo, ancho, matriz4, matriz3);
    if(abs(error) < abs(errorMin) || !errorMin){
      errorMin = error;
      j = i;
    }
    errores[i]=error;

  //PASO 5: Hacemos la actualización de matriz1 y matriz2
    ecuacionesCorregir(largo, ancho, features, matriz1, matriz2, matriz3, n);
    ecuacionesCorregir(ancho, largo, features, matriz2, matriz1, matriz2, n/10);
    if(error<errorMax)
      break;
  }


}
