#include "usuarios.h"
#include "vista.h"
#include "mysql_modulo.h"
#define TRUE 1
#define FALSE 0

//Regresa el  Id del Usuario
int usuariosLoginUsuario(MYSQL* con, char * usuario, char contrasena[])
{
    char queryLogin[150];
    int validarLogin=FALSE;
    
    int filas=0, idUsuario = 0;
    char** resultados;
    sprintf(queryLogin, "SELECT id_usuario FROM usuarios WHERE (username= '%s' AND password= '%s')", usuario, contrasena);
    resultados=mysql_readquery(queryLogin, con, &filas);
    
	if(filas==0)
    {
    	printf("ERROR: esta combinacion de usuario/contrasena no existe.\n");
        rewind(stdin);
        return FALSE;
    }
    
    sscanf(resultados[0],"%d", &idUsuario);
    rewind(stdin);
    free(resultados);
    return idUsuario;

}

int usuariosRegistrarUsuario(MYSQL* con, char usuario[], char contrasena[], char nombre[], char genero, int edad)
{
    char queryRegistro[150];
    int validarRegistro=FALSE;
    int filas = 0;
    
    //Validar que no exista el usuario.
    sprintf(queryRegistro, "SELECT id_usuario FROM usuarios WHERE (username= '%s')", usuario);
    mysql_readquery(queryRegistro, con, &filas);
    
    if(filas!=0)
    {
    	printf("ERROR: este usuario ya existe.\n");
        return FALSE;
    }
    
    sprintf(queryRegistro, "INSERT INTO usuarios VALUES (NULL, '%s', '%s', '%s', %d, '%c')", usuario, contrasena, nombre, edad, genero);

    if(!mysql_doquery(queryRegistro, con))
    {
        printf("ERROR: no se pudo registrar el usuario.\n");
        return FALSE;
    }
    
    return TRUE;
}


void usuariosAgregarCalificacion(MYSQL* con, int idUsuario, char nombrepelicula[100], int calificacion)
{
    char query[250];
    sprintf(query, "SELECT id_peliculas FROM peliculas WHERE titulo='%s'", nombrepelicula);
    //printf("%s\n", query);
    char ** resultados;
    int filas = 0;
    int idPelicula, validacion;
    resultados = mysql_readquery(query, con, &filas);
    if (filas == 0)
    {
       
        printf("ERROR: no existe la pelicula.\n");
        return;
    }
    rewind(stdin);
    sscanf(resultados[0], "%d", &idPelicula);
    printf("%d\n", idPelicula);
    sprintf(query, "SELECT calificacion FROM calificacion_peliculas WHERE id_pelicula=%d and id_usuario=%d", idPelicula, idUsuario);
    resultados= mysql_readquery(query, con, &filas);
    if (filas == 0)
    {
        sprintf(query, "INSERT INTO calificacion_peliculas VALUES (%d, %d, %d)", idUsuario, idPelicula, calificacion);
    }
    else
    {
        sprintf(query, "UPDATE calificacion_peliculas SET calificacion=%d WHERE (id_usuario=%d AND id_pelicula=%d)", calificacion, idUsuario, idPelicula);
    }
    
    //printf("%s\n", query);
    validacion = mysql_doquery(query, con);
    if (validacion == 0)
    {
        printf("ERROR: no se pudo agregar el query.\n");
        return;
    }
    printf("Se agrego exitosamente.\n");
    free(resultados);
}
