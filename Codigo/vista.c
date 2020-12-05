//
//  vista.c
//
//
//  Created by Equipo 2 - 01/dic/2020
//
/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include "vista.h"
char vistaMenuLoginRegistro()
{
    char op;
    printf("Bienvenido a PelisChidas.c om!\n");
    printf("\t1.-Login.\n");
    printf("\t2.-Registrar.\n");
    printf("Selecciona tu opcion:\n");
    scanf("%c", &op);
    rewind(stdin);
    return op;
}

void vistaLogin(char * usuario, char * contrasena)
{
    
    
    printf("Inicia sesion en PelisChidas.c om!\n");
    printf("\tDame tu usuario: ");
    fgets(usuario, 25, stdin);
    usuario[(strlen(usuario)-1)]=0;
    rewind(stdin);
    printf("\n\tDame tu contrasena: ");
    fgets(contrasena, 25, stdin);
    contrasena[(strlen(contrasena)-1)]=0;
    rewind(stdin);
}
void vistaRegistro(char * usuario, char * contrasena, char *nombre, char *genero, int *edad)
{
    printf("Registrate a PelisChidas.c om!\n");
    printf("\tDame tu usuario: ");
    fgets(usuario, 25, stdin);
    usuario[(strlen(usuario)-1)]=0;
    rewind(stdin);
    printf("\n\tDame tu contrasena: ");
    fgets(contrasena, 25, stdin);
    contrasena[(strlen(contrasena)-1)]=0;
    rewind(stdin);
    printf("\n\tDame tu nombre: ");
    fgets(nombre, 50, stdin);
    nombre[(strlen(nombre)-1)]=0;
    rewind(stdin);
    *genero='y';
    while(*genero!='M' && *genero!='F' && *genero!='O')
    {
        printf("\n\tDame tu genero (M, F, O): ");
        scanf("%c", genero);
        rewind(stdin);
    }
    printf("\n\tDame tu edad: ");
    scanf("%d", edad);
    rewind(stdin);
}
char vistaMenu(char * usuario)
{
    char op;
    printf("Bienvenido %s !\n", usuario);
    printf("\t1.-Agregar pelicula.\n");
    printf("\t2.-Calificar pelicula.\n");
    printf("\t3.-Ver recomendaciones de peliculas.\n");
    printf("\t4.-Ver recomendaciones de amigos.\n");
    printf("\t5.-Ver todas las peliculas.\n");
    printf("\t6.-Salir.\n");
    printf("Dame tu opcion: ");
    scanf("%c", &op);
    rewind(stdin);
    return op;
}
void vistaContinuar()
{
    char cont;
    printf("Presiona <enter> para continuar... ");
    scanf("%c", &cont);
    rewind(stdin);
}
void vistaAgregarPelicula(Peliculas * peliNueva)
{
    printf("Dime el nombre de la pelicula: ");
    fgets(peliNueva->titulo, 98, stdin);
    peliNueva->titulo[(strlen(peliNueva->titulo) - 1)] = 0;
    rewind(stdin);
    printf("Dime el director: ");
    fgets(peliNueva->director, 48, stdin);
    peliNueva->director[(strlen(peliNueva->director) - 1)] = 0;
    rewind(stdin);
    printf("Dime el actor principal: ");
    fgets(peliNueva->actor_principal, 48, stdin);
    peliNueva->actor_principal[(strlen(peliNueva->actor_principal) - 1)] = 0;
    rewind(stdin);
    printf("Dime ela casa productora: ");
    fgets(peliNueva->casa_productora, 98, stdin);
    peliNueva->casa_productora[(strlen(peliNueva->casa_productora) - 1)] = 0;
    rewind(stdin);
    printf("Del 1 al 100 que tanto drama tiene: ");
    scanf("%d", &(peliNueva->drama));
    rewind(stdin);
    printf("Del 1 al 100 que tanta accion tiene: ");
    scanf("%d", &(peliNueva->accion));
    rewind(stdin);
    printf("Del 1 al 100 que tanta animacion tiene: ");
    scanf("%d", &(peliNueva->animacion));
    rewind(stdin);
    printf("Del 1 al 100 que tanto terror tiene: ");
    scanf("%d", &(peliNueva->terror));
    rewind(stdin);
    printf("Del 1 al 100 que tanta comedia tiene: ");
    scanf("%d", &(peliNueva->comedia));
    rewind(stdin);
    printf("Dime la duracion en minutos enteros: ");
    scanf("%d", &(peliNueva->duracion));
    rewind(stdin);
    printf("Dime el anio de publicacion: ");
    scanf("%d", &(peliNueva->anio_publicacion));
    rewind(stdin);
    peliNueva->G = 0;
    peliNueva->PG13 = 0;
    peliNueva->R = 0;
    printf("Es clasificacion G? 1 si sí, 0 si no: ");
    scanf("%d", &(peliNueva->G));
    rewind(stdin);
    if (peliNueva->G == 0)
    {
        printf("Es clasificacion PG-13? 1 si sí, 0 si es clasificacion R: ");
        scanf("%d", &(peliNueva->PG13));
        rewind(stdin);
        if (peliNueva->PG13 == 0)
        {
            peliNueva->R = 1;
        }
        else peliNueva->PG13 = 1;
    }
    else peliNueva->G = 1;
}
void vistaAgregarCalificacion(char* nombrePelicula, int* calificacion)
{
    printf("Dime el nombre de la pelicula que quieres calificar: ");
    fgets(nombrePelicula, 98, stdin);
    nombrePelicula[strlen(nombrePelicula) - 1] = 0;
    rewind(stdin);
    printf("Del 1 al 5, cuanto le pones?: ");
    scanf("%d", calificacion);
    rewind(stdin);
}