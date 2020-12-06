#ifndef struct_h
#define struct_h
#define FEATURES 5
struct Struct_Pelis
{
    char titulo[100], director[50], actor_principal[50], casa_productora[100];
    int drama, accion, animacion, terror, comedia, G, PG13, R, duracion, anio_publicacion;
};
typedef struct Struct_Pelis Peliculas;
typedef struct _data {
	int id_usuario;
	short int edad;
	int id_pelicula;
	char titulo[60];
	short int drama;
	short int accion;
	short int animacion;
	short int terror;
	short int comedia;
	short int G;
	short int PG13;
	short int R;

	char actor_principal[60];
	char casa_productora[60];
	short int duracion;
	short int anio_publicacion;

	short int calificacion;

}DATA;

#define TRUE 1
#define FALSE 0
#define FEATURES 5
#define EPOCS 1000
#endif
