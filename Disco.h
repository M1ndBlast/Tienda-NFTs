#pragma once

#include "Producto.h"

class Disco : public Producto {
	protected:
		string artista;
		string disquera;
		int noCanciones;
	public:
		Disco() : Producto() {
			tipo = string("disco");
			artista = string("");
			disquera= string("");
			noCanciones = 0;
		}

		Disco(const Disco& disco) : Producto(disco) {
			artista = disco.artista;
			disquera = disco.disquera;
			noCanciones = disco.noCanciones;
		};

		Disco(double precio, double descuento, string nombre, string tipo, string artista, string disquera, int noCanciones) : Producto(precio, descuento, nombre, tipo) {
			this->artista = artista;
			this->disquera = disquera;
			this->noCanciones = noCanciones;
		};

		string getArtista();
		string getDisquera();
		int getNoCanciones();
		static string getAttributes();
};