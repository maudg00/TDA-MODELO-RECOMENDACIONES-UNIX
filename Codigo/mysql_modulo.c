//
//  mysql_modulo.h
//
//
//  Created by Equipo 2 - 03/dic/2020
//

#include "mysql_modulo.h"
#include <string.h>


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
char ** mysql_readquery(char query[], MYSQL* con, int *filas)
{
    int totalfilas=0;
    char **resultados=NULL;
    int i;
    if (mysql_query(con, query))
    {
        printf("ERROR QUERY: %s", query);
        return NULL;
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
        *filas=0;
        printf("QUERY VACIO.\n");
        return NULL;
    }
    MYSQL_ROW row;
    int num_fields;
    
    while ((row = mysql_fetch_row(result)))
    {
        totalfilas=totalfilas+1;
    }
    mysql_free_result(result);

    resultados=malloc(sizeof(char*)*totalfilas);
    
    for(i=0; i<totalfilas;i++)
    {
        *(resultados+i)=malloc(sizeof(char)*500);
    }

    if (mysql_query(con, query))
    {
        printf("ERROR QUERY");
        return NULL;
    }
    MYSQL_RES *result2 = mysql_store_result(con);
    if (result2 == NULL)
    {
        *filas=0;
        printf("QUERY VACIO.\n");
        return NULL;
    }
    num_fields=mysql_num_fields(result2);
    MYSQL_ROW row2;
  
    i=0;
    while ((row2 = mysql_fetch_row(result2)))
    {
        char string[500];
        string[0]=0;
        for(int j = 0; j < num_fields; j++)
        {
            if(j==0)
            {
                strcat(string, row2[j]);
            }
            else
            {
                strcat(string, ",");
                strcat(string, row2[j]);
            }
        }
        strcpy(*(resultados+i), string);
        i+=1;
    }
    mysql_free_result(result2);
    *filas=totalfilas;
    return resultados;
}

/*
 *
 * Establece la conexion con la base de datos
 *
 * @params
 *      void

 * @returns
        MYSQL * conexion
*/
void mysql_startconnection(MYSQL *mysql){
   mysql_init(mysql);
   mysql_real_connect(mysql, "localhost", "ib18mgh", "209667", "ib18mgh", 0, NULL, 0);
}

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
int mysql_doquery(char query[], MYSQL *con){
	if (mysql_query(con, query))
    {
    	printf("ERROR QUERY");
        return FALSE;
    }
	
	return TRUE;		
}
