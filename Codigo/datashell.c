/*#include "datashell.h"

DATA * datashell_getData(char **data, int SIZE){
	DATA *d;
	d = malloc(sizeof(DATA) * SIZE);
	for(int i=0; i<SIZE; i++){
		sscanf(data[i], "%i,%hi,%i,%[^,],%hi,%hi,%hi,%hi,%hi,%hi,%hi,%hi,%[^,],%[^,],%hi,%hi,%[^,]", 
			&d[i].id_usuario,
			&d[i].edad,
			&d[i].id_pelicula,
			 d[i].titulo,
			&d[i].drama,
			&d[i].accion,
			&d[i].animacion,
			&d[i].terror,
			&d[i].comedia,
			&d[i].G,
			&d[i].PG13,
			&d[i].R,
			 d[i].actor_principal,
			 d[i].casa_productora,
			&d[i].duracion,
			&d[i].anio_publicacion,
			&d[i].calificacion);
	}
	
	return d;
}*/

