//
//  mysql_modulo.h
//
//
//  Created by Equipo 2 - 3/dic/2020
//

#ifndef mysql_modulo_h
#define mysql_modulo_h

/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include <stdio.h>
#include <mysql.h>

/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/


/* Constants declarations. */

/* Set EXTERN macro: */

#ifndef mysql_modulo_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif


/* Global variables declarations. */
//
//


/*
 *
 * Funcion que realiza query SQL y regresa un arreglo con los resultados
 *
 * @params
 *      query (char *):
            Query SQL select a realizar
 
 		con (MYSQL *):
            Conexion a la base de datos
        
        filas (int *)
        	Pointer para guardar el numero de filas resultantes

 * @returns
        char ** resultados
*/
EXTERN char ** mysql_readquery(char query[], MYSQL *con, int* filas);

/*
 *
 * Establece la conexion con la base de datos
 *
 * @params
 *      void

 * @returns
        MYSQL * conexion
*/
EXTERN MYSQL * mysql_startconnection();

/*
 *
 * Funcion que realiza query SQL y regresa una boolean
 *
 * @params
 *      query (char *):
            Query SQL select a realizar
 
 		con (MYSQL *):
            Conexion a la base de datos

 * @returns
        int boolean
*/
EXTERN int  mysql_doquery(char query[], MYSQL *con);


#undef mysql_modulo_IMPORT
#undef EXTERN
#endif /* mysql_modulo_h */
