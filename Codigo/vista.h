
//
//  vista.h
//
//
//  Created by Equipo 2 - 01/dic/2020
//

#ifndef vista_h
#define vista_h

/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include <stdio.h>
#include "structs.h"
#include <string.h>
/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/



/* Set EXTERN macro: */

#ifndef vista_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif


/* Global variables declarations. */
//
//
EXTERN char vistaMenuLoginRegistro();
EXTERN void vistaLogin(char * usuario, char * contrasena);
EXTERN void vistaRegistro(char* usuario, char* contrasena, char* nombre, char* genero, int* edad);
EXTERN char vistaMenu(char *usuario);
EXTERN void vistaContinuar();
EXTERN void vistaAgregarPelicula(Peliculas *peliNueva);
EXTERN void vistaAgregarCalificacion(char *nombrePelicula, int *calificacion);
EXTERN void vistaGraficarError();
#undef vista_IMPORT
#undef EXTERN
#endif
