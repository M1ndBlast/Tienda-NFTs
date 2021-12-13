#include "Disco.h"

string Disco::getArtista()
	{ return artista; }

string Disco::getDisquera()
	{ return disquera; }

int Disco::getNoCanciones()
	{ return noCanciones; }

string Disco::getAttributes()
	{ return Producto::getAttributes().append("ARTISTA\tNO_CANCIONES\tDISQUERA\t"); }
