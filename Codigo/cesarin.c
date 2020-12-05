//
//  main.c
//  TDA
//
//  Created by bernardo on 02/12/20.
//

#include "cesarin.h"




void cesarinObtenerAficiones(float** peliculas, float* calificaciones, size_t num_pelis, float* aficiones) {
	float* entrenamiento[1];
	float *usuarios[1];
	float *ratings[1];
	float errores[1000];

	entrenamiento[0] = malloc(sizeof(float) * num_pelis);
	ratings[0] = malloc(sizeof(float) * num_pelis);
	usuarios[0] = malloc(sizeof(float) * FEATURES);
	ecuacionesCopy(entrenamiento, calificaciones);
	//ratings=memoriaMatriz(1, num_pelis);
    ecuacionesStochasticGradientDescent(1, (int)num_pelis, FEATURES, 1000,
  errores, usuarios, peliculas, ratings, entrenamiento);
	 for(int i=0; i<FEATURES; i++){
		 if ((usuarios)[0]+i != NULL && aficiones!=NULL)
		 {
			 printf("AAAAAAAAA %f\n", *(*(usuarios)+i));
			 *(aficiones + i) = *(*(usuarios)+i);
		 }
		 
	  }
	 
	 free(entrenamiento[0]);
	 free(usuarios[0]);
	 free(ratings[0]);
}

void cesarinRecomendarPeliculas(float **peliculas, size_t num_pelis, float *aficiones, float *prediccion){
	ecuacionesRecomendacion(num_pelis, FEATURES, aficiones, prediccion, peliculas);
}