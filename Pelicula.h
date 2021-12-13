#pragma once

#include "Producto.h"

class Pelicula : public Producto {
	protected:
		int duracion;
		string clasificacion;

	public:
		Pelicula() : Producto() {
			tipo = string("libro");
			clasificacion = string("");
			duracion: 0.0;
		}

		Pelicula(const Pelicula& pelicula) : Producto(pelicula) {
			duracion = pelicula.duracion;
			clasificacion = pelicula.clasificacion;
		};

		Pelicula (double precio, double descuento, string nombre, string tipo, int duracion, string clasificacion) : Producto(precio, descuento, nombre, tipo) {
			this->duracion = duracion;
			this->clasificacion = clasificacion;
		};

		string getClasificacion();
		int getDuracion();
		static string getAttributes();
};