#pragma once
#include <string>
using namespace std;

class Producto {
	protected:
		double precio;
		double descuento;
		string nombre;
		string tipo;

	public:
		Producto();
		Producto(const Producto &producto);
		Producto(double precio, double descuento, string nombre, string tipo);

		double getPrecio();
		double getDescuento();
		string getNombre();
		string getTipo();
		static string getAttributes();
};