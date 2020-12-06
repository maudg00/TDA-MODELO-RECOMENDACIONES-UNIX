//
//  modelo.c
//
//
//  Created by Equipo 2 - 03/dic/2020
//



/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include "modelo.h"
#include "cesarin.h"
/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/



/* Global variables declarations. */
//
//

void arrayInPercentage(float *array, int size, int *ids);


/*
 *
 * Funcion puente entre el contenedor y el modulo SQL
 *
 * @params
 *      void
 
 * @returns
        MYSQL * conexion
*/
void modeloIniciarConexion(MYSQL * con)
{
	mysql_startconnection(con);
}

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
int modeloQueryNumeroFilas(char query[], MYSQL* con)
{
	int filas = 0;
	mysql_readquery(query, con, &filas);
	return filas;
}

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
void modeloAgregarPelicula( Peliculas pelicula, MYSQL* con)
{
	int filas = 0;
	char queryInsertar[500];
	sprintf(queryInsertar, "SELECT id_peliculas FROM peliculas WHERE titulo='%s'", pelicula.titulo);
	mysql_readquery(queryInsertar, con, &filas);
	if (filas != 0)
	{
		printf("ERROR: ya existe esta pelicula.\n");
		return;
	}
	printf("%d\n", pelicula.duracion);
	sprintf(queryInsertar, "INSERT INTO peliculas VALUES(NULL, '%s', %d, %d, %d, %d, %d, %d, %d, %d, '%s', '%s', '%s', %d, %d)", pelicula.titulo, pelicula.drama, pelicula.accion, pelicula.animacion, pelicula.terror, pelicula.comedia, pelicula.G, pelicula.PG13, pelicula.R, pelicula.director, pelicula.actor_principal, pelicula.casa_productora, pelicula.duracion, pelicula.anio_publicacion);
	int validacion = mysql_doquery(queryInsertar, con);
	if (validacion == 0)
	{
		printf("ERROR: No se pudo subir la pelicula.\n");
	}
	else printf("La pelicula se subio exitosamente.\n");
}

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
void modeloVerPeliculas(MYSQL* con)
{
	int filas = 0;
	char queryPeliculas[] = "SELECT * FROM peliculas";
	char** resultados;
	int columnas;
	resultados = mysql_readquery(queryPeliculas, con, &filas);
	if (filas == 0)
	{
		printf("No hay peliculas.\n");
	}
	if (resultados == NULL)
	{
		printf("ERROR OBTENIENDO PELICULAS.\n");
	}
	else
	{
		
		for (int i = 0; i < filas; i++)
		{
			columnas = (int)strlen(*(resultados + i));
			for (int j = 0; j < columnas;j++)
			{
				 printf("%c", *(*(resultados + i) + j));
			}
			printf("\n");
		}
		
	}
	
}

void modeloObtenerVectorAficiones(MYSQL *con, int idUsuario, float *aficiones, int to_file){
	int filas = 0, i, j;
	char queryPeliculas[250];
	char** resultados;
	float **peliculas=NULL, *calificaciones=NULL;
	
	sprintf(queryPeliculas, "SELECT p.drama, p.accion, p.animacion, p.terror, p.comedia, c.calificacion FROM peliculas p INNER JOIN calificacion_peliculas c ON p.id_peliculas= c.id_pelicula WHERE id_usuario = %d", idUsuario);
	resultados = mysql_readquery(queryPeliculas, con, &filas);
	if (resultados == NULL || filas == 0)
	{
		for(i=0; i<FEATURES; i++){
			aficiones[i] = (float)0.6;
		}
		return;
	}
	
	calificaciones = malloc(filas * sizeof(float));
	peliculas = (float **)malloc(filas * sizeof(float *));
	if(peliculas==NULL)
	{
		return;
	}
	if (calificaciones == NULL) return;
	
	for(i=0; i<filas; i++){
		peliculas[i] = malloc(FEATURES * sizeof(float));
	}
	
	for(i=0; i<filas; i++){
		if (peliculas[i] != NULL)
		{
			if(sscanf(*(resultados + i), "%f,%f,%f,%f,%f,%f", &peliculas[i][0], &peliculas[i][1], &peliculas[i][2], &peliculas[i][3], &peliculas[i][4], &calificaciones[i]));
		}
		
		calificaciones[i]/=(float)5.0;
		for(j=0; j<FEATURES; j++){
			if (peliculas[i] != NULL)
			{
				peliculas[i][j] /= 100.0;
			}

		}
		
	}
	
	cesarinObtenerAficiones(peliculas, calificaciones, filas, aficiones, 1);
        
	//Frees
	for(i=0; i<filas; i++){
		free(peliculas[i]);
	}
	free(peliculas);
	free(calificaciones);
	
	return;
}


float * modeloObtenerPeliculasRecomendadas(MYSQL *con, int idUsuario,float *aficiones){
	int filas = 0, i, j;
	char queryPeliculas[250];
	char** resultados;
	float **peliculas, *prediccion;
	int *ids;

	system("clear");
        sprintf(queryPeliculas, "SELECT distinct p.id_peliculas, p.drama, p.accion, p.animacion, p.terror, p.comedia FROM peliculas p;");

	resultados = mysql_readquery(queryPeliculas, con, &filas);


	prediccion = malloc(sizeof(float) * filas);
	ids = malloc(sizeof(int) * filas);
	peliculas = malloc(sizeof(float *) * filas);
	for(i=0; i<filas; i++){
	  peliculas[i] = malloc(sizeof(float) * FEATURES);
	  for(j=0; j<FEATURES; j++){
	    peliculas[i][j] = 0;
	  }
	}
	
	for(i=0; i<filas; i++){
	  sscanf(resultados[i], "%i,%f,%f,%f,%f,%f", &ids[i], &peliculas[i][0], &peliculas[i][1], &peliculas[i][2], &peliculas[i][3], &peliculas[i][4]);
	  for(j=0; j<FEATURES; j++){
	    if (peliculas[i] != NULL)
	      {
		peliculas[i][j] /= 100.0;
	      }

	  }
	}

	
	cesarinRecomendarPeliculas(peliculas, filas, aficiones, prediccion);

	arrayInPercentage(prediccion, filas, ids);
	
	for(i=0; i<filas; i++){
	  sprintf(queryPeliculas, "SELECT titulo FROM peliculas p WHERE id_peliculas = %i;", ids[i]);
	  resultados = mysql_readquery(queryPeliculas, con, &j);
	  printf("%s = %f\n", resultados[0], prediccion[i]);	  
	}


	free(ids);
	for(i=0; i<filas; i++){
	  free(peliculas[i]);
	}
	free(peliculas);
	free(prediccion);		
}



void modeloRecomendarAmigos(MYSQL *con, int idUsuario,float *user_aficiones){
  int filas, i, *ids, j;
  float** aficiones, *prediccion;
  char **resultados, query[200];
  

  sprintf(query, "SELECT id_usuario FROM usuarios WHERE id_usuario != %d;", idUsuario);
  resultados = mysql_readquery(query, con, &filas);

  if(!resultados){
    printf("El wey de la base no sabe hacer queries\n");
    return;
  }

  if (filas == 0)
    {
      printf("Que chistoso... eres el unico usuario....\nVamos a quebrar :(");
      return;
    }

  modeloObtenerVectorAficiones(con, idUsuario, user_aficiones, 0);

  
  ids = malloc(sizeof(int) * filas);
  prediccion = malloc(sizeof(float) * filas);
  aficiones = malloc(sizeof(float *) * filas);
  for(i=0; i<filas; i++){
    aficiones[i] = malloc(sizeof(float) * FEATURES);
    sscanf(resultados[i], "%i", &ids[i]);
    modeloObtenerVectorAficiones(con, ids[i], aficiones[i], 0);

  }

  cesarinRecomendarPeliculas(aficiones, filas, user_aficiones, prediccion);

  arrayInPercentage(prediccion, filas, ids);
  
  for(i=0; i<filas; i++){
    sprintf(query, "SELECT username FROM usuarios WHERE id_usuario = %i;", ids[i]);
    resultados = mysql_readquery(query, con, &j);
    printf("%s = %f\n", resultados[0], prediccion[i]);	  
  }


  free(ids);
  for(i=0; i<filas; i++){
    free(aficiones[i]);
  }
  free(aficiones);
  free(prediccion);
	
}

void arrayInPercentage(float *array, int size, int *ids){
  int i, j;
  float k;
  for(i=size-1; i; i--){
    for(j=0; j<i; j++){
      if(array[j]<array[j+1]){
	k=array[j];
	array[j] = array[j+1];
	array[j+1] = k;

	k=ids[j];
	ids[j] = ids[j+1];
	ids[j+1] = (int)k;
      }
    }
  }

  k=array[0];
  for(i=0; i<size; i++){
    array[i] = (array[i]/k) * 100;
  }
  
}
