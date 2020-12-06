//
//  cesarin.h
//  TDA
//
//  Created by Equipo 2 on 29/11/20.
//

#ifndef cesarin_h
#define cesarin_h

#include <stdio.h>
#include "ecuaciones.h"
//#include "memoria.h"
#include "structs.h"
//#include "pipes.h"
//#include "debug.h"



/* Set EXTERN macro: */

#ifndef cesarin_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

 EXTERN void cesarinObtenerAficiones(float **peliculas, float *calificaciones, size_t num_pelis, float *aficiones, int to_file);
EXTERN void cesarinRecomendarPeliculas(float **peliculas, size_t num_pelis, float *aficiones, float *prediccion);
/*
  Manda a llamar todo lo del modelo predictivo.
  @params
  @return
*/

#endif /* cesarin_h */
