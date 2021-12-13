#include "Producto.h"

Producto::Producto() {
	precio = 0.0;
	descuento = 0.0;
	nombre = string("");
	tipo = string("");
}

Producto::Producto(const Producto& producto) {
	precio = producto.precio;
	descuento = producto.descuento;
	nombre = producto.nombre;
	tipo = producto.tipo;
}

Producto::Producto(double precio, double descuento, string nombre, string tipo) {
	this->precio = precio;
	this->descuento = descuento;
	this->nombre = nombre;
	this->tipo = tipo;
}

double Producto::getPrecio()
	{ return precio; }
double Producto::getDescuento() 
	{ return descuento; }
string Producto::getNombre() 
	{ return nombre; }
string Producto::getTipo() 
	{ return tipo; }

string Producto::getAttributes() 
	{ return "NOMBRE\tPRECIO\tDESCUENTO\t"; }
