#pragma once

#include "Producto.h"

class Libro : public Producto {
	protected:
		string autor;
		string editorial;
		string edicion;
		int noPaginas;

	public:
		Libro() : Producto() {
			tipo = string("libro");
			autor = string("");
			editorial = string("");
			edicion = string("");
			noPaginas = 0;
		}

		Libro(const Libro& libro) : Producto(libro) {
			autor = libro.autor;
			edicion = libro.edicion;
			editorial = libro.editorial;
			noPaginas = libro.noPaginas;
		};

		Libro(double precio, double descuento, string nombre, string tipo, string autor, string editorial, string edicion, int no_paginas) : Producto(precio, descuento, nombre, tipo) {
			this->autor = autor;
			this->editorial = editorial;
			this->edicion = edicion;
			this->noPaginas = no_paginas;
		};

		string getAutor();
		string getEditoria();
		string getEdicion();
		int getNoPaginas();
		static string getAttributes();
};