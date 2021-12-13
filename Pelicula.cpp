#include "Pelicula.h"

string Pelicula::getClasificacion() 
	{ return clasificacion; }

int Pelicula::getDuracion()
	{ return duracion; }

string Pelicula::getAttributes()
{ return Producto::getAttributes().append("DURACIÓN\tCLASIFICACIÓN\t"); }