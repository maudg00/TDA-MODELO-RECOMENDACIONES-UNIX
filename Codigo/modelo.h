//
//  modelo.h
//
//
//  Created by Equipo 2 - 03/dic/2020
//

#ifndef modelo_h
#define modelo_h

/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include <stdio.h>
#include <mysql/mysql.h>
#include "mysql_modulo.h"
#include <string.h>
#include "structs.h"
#include "cesarin.h"
/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/



/* Set EXTERN macro: */

#ifndef modelo_IMPORT
#define EXTERN
#else
#define EXTERN extern
#endif


/* Global variables declarations. */
//
//

/*
 *
 * Funcion puente entre el contenedor y el modulo SQL
 *
 * @params
 *      void
 
 * @returns
        MYSQL * conexion
*/
EXTERN void modeloIniciarConexion(MYSQL * con);

/*
 *
 * Funcion que realiza el query indicado y regresa el numero de filas
 * resultante
 *
 * @params
 *      query (char *)
        	Query SQL a realizar
        	
 		con (MYSQL *):
            Conexion a la base de datos

 * @returns
        int filas
*/
EXTERN int modeloQueryNumeroFilas(char query[], MYSQL* con);

/*
 *
 * Funcion que realiza el query indicado y regresa el numero de filas
 * resultante
 *
 * @params
 *      peliculas (Peliculas)
        	Instancia de la estructura Pelicula para guardar la informacion de esta
        	
 		con (MYSQL *):
            Conexion a la base de datos

 * @returns
        void
*/
EXTERN void modeloAgregarPelicula(Peliculas pelicula, MYSQL* con);

/*
 *
 * Funcion que nos muestra la informacion de todas las peliculas 
 * registradas
 *
 * @params
 *      con (MYSQL *):
            Conexion a la base de datos

 * @returns
        void
*/
EXTERN void modeloVerPeliculas(MYSQL* con);

EXTERN void modeloObtenerVectorAficiones(MYSQL *con, int idUsuario, float *aficiones, int to_file);
EXTERN float * modeloObtenerPeliculasRecomendadas(MYSQL *con, int idUsuario,float *aficiones);
EXTERN void modeloRecomendarAmigos(MYSQL *con, int idUsuario,float *user_aficiones);


#undef modelo_IMPORT
#undef EXTERN
#endif /* modelo_h */
