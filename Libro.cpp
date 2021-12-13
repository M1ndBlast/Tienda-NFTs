#include "Libro.h"

string Libro::getAutor()
	{ return autor; }
string Libro::getEditoria()
	{ return editorial; }
string Libro::getEdicion()
	{ return edicion; }
int Libro::getNoPaginas()
	{ return noPaginas; }

string Libro::getAttributes()
{ return Producto::getAttributes().append("EDITORIA\tEDICION\tNO_PAGS\tAUTOR\t"); }
