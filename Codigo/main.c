//
//  main.c
//  
//
//  Created by Equipo 2 - 01/dic/2020
//

#include "structs.h"
#include <stdlib.h>
#include "modelo.h"

#include <stdio.h>
//#include "datashell.h"
#include "vista.h"
#include "usuarios.h"

/* Constants declarations. */
#define TRUE 1
#define FALSE 0
#define FEATURES 5

void loginYRegistro(MYSQL *con, int *idUsuario, char usuario[27]);
void menuPrincipal(MYSQL *con, int idUsuario, char usuario[27]);

int main()
{
    MYSQL con;
    modeloIniciarConexion(&con);
    int idUsuario = 0;
    char usuario[27];
    //char queryABT[]="SELECT u.id_usuario, u.edad, p.id_pelicula, p.titulo, u.genero, p.drama, p.accion, p.animacion, p.terror, p.comedia, p.G, p.PG13, p.R, p.actor_principal, p.casa_productora, p.duracion, p.anio_publicacion,  c.calificacion FROM usuarios u LEFT JOIN calificacion_peliculas c USING (id_usuario) LEFT JOIN peliculas p ON (p.id_peliculas=c.id_pelicula)";

	loginYRegistro(&con, &idUsuario, usuario);
	//Calcular aficiones
	menuPrincipal(&con, idUsuario, usuario);
	mysql_close(&con);
    
    /*ResultadosQuery=mysql_readquery(query, con, &filas);
    datashell_getData(ResultadosQuery, filas);*/
}


/*
 *
 * Funcion de inicio que permirte registrar un nuevo usuario, así como logearse 
 *
 * @params
 *      con (MYSQL *):
            Conexion a la base de datos
        
        idUsuario (int *)
        	Pointer a la variable que almacena el id del Usuario logeado
        
        usuario (char *)
        	Almacena el nombre de usuario

 * @returns
        void
*/
void loginYRegistro(MYSQL *con, int *idUsuario, char usuario[27]){
	char contrasena[27], nombre[50], genero;
	int validar, edad;
	char opcionMenu;
    validar = FALSE;
    int validarR = FALSE;
	while(validar==FALSE)
    {
        opcionMenu=vistaMenuLoginRegistro();
        system("clear");
        switch (opcionMenu)
        {
        case '1':
            do
            {
                vistaLogin(usuario, contrasena);
                *idUsuario = usuariosLoginUsuario(con, usuario, contrasena);
            } while (*idUsuario == FALSE);
            
            validar=TRUE;
        break;
        case '2':
            do
            {
            	vistaRegistro(usuario, contrasena, nombre, &genero, &edad);
                validarR = usuariosRegistrarUsuario(con, usuario, contrasena, nombre, genero, edad);
            } while (validarR == FALSE);
        break;
        default:
            printf("ERROR: opcion invalida.\n");
        break;
        }
        vistaContinuar();
    }	
}

/*
 *
 * Presenta el menu de recomendaciones y administracion de peliculas
 *
 * @params
 *      con (MYSQL *):
            Conexion a la base de datos
        
        idUsuario (int *)
        	Pointer a la variable que almacena el id del Usuario logeado
        
        usuario (char *)
        	Almacena el nombre de usuario

 * @returns
        void
*/

void menuPrincipal(MYSQL *con, int idUsuario, char usuario[27]){
	char opcionMenu;
    Peliculas peliNueva;
    char nombrePelicula[100];
    int Calificacion;
    float *aficiones;
    aficiones = malloc(FEATURES * sizeof(float));
	do
    {
        system("clear");
        opcionMenu=vistaMenu(usuario);
        switch(opcionMenu)
        {
            case '1':
                printf("%d\n", idUsuario);
                vistaAgregarPelicula(&peliNueva);
                modeloAgregarPelicula(peliNueva, con);
            break;
            case '2':
                printf("Calificar Pelicula.\n");
                vistaAgregarCalificacion(nombrePelicula, &Calificacion);
                usuariosAgregarCalificacion(con, idUsuario, nombrePelicula, Calificacion);
            break;
            case '3':
                printf("Ver Recomendaciones P.\n");
                modeloObtenerVectorAficiones(con, idUsuario, aficiones, 1);
                modeloObtenerPeliculasRecomendadas(con, idUsuario,aficiones);
                vistaGraficarError();
            break;
            case '4':
                printf("Ver Recomendaciones A.\n");
                modeloRecomendarAmigos(con, idUsuario, aficiones);
            break;
            case '5':
                printf("Ver todas las peliculas.\n");
                modeloVerPeliculas(con);
            break;
            case '6':
                printf("Salir.\n");
            break;
            default:
                printf("ERROR: opcion equivocada.\n"); 
            break;
        }
        vistaContinuar();
    } while (opcionMenu!='6');
}

