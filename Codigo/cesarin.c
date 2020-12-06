//
//  main.c
//  TDA
//
//  Created by bernardo on 02/12/20.
//

#include "cesarin.h"
#include "pipes.h"



void cesarinObtenerAficiones(float** peliculas, float* calificaciones, size_t num_pelis, float* aficiones, int to_file) {
	float* entrenamiento[1];
	float *usuarios[1];
	float *ratings[1];
	float errores[EPOCS];
	FILE *fp;
	int i;
	
	entrenamiento[0] = malloc(sizeof(float) * num_pelis);
	ratings[0] = malloc(sizeof(float) * num_pelis);
	
	usuarios[0] = malloc(sizeof(float) * FEATURES);
	ecuacionesCopy(entrenamiento, calificaciones, num_pelis);
        
    ecuacionesStochasticGradientDescent(1, (int)num_pelis, FEATURES, EPOCS,
  errores, usuarios, peliculas, ratings, entrenamiento);
	 for(int i=0; i<FEATURES; i++){
		 if ((usuarios)[0]+i != NULL && aficiones!=NULL)
		 {
			 *(aficiones + i) = *(*(usuarios)+i);
		 }
		 
	  }	
	 
	 free(entrenamiento[0]);
	 free(usuarios[0]);
	 free(ratings[0]);

	 if(!to_file){
	   return;
	 }

	 fp = pipesWriteNewFile("cesarin.csv");
	 pipesWrite(fp, errores, EPOCS);
	 pipesCloseFile(fp);
	 
}

void cesarinRecomendarPeliculas(float **peliculas, size_t num_pelis, float *aficiones, float *prediccion){
  ecuacionesRecomendacion(num_pelis, FEATURES, aficiones, prediccion, peliculas);
}
