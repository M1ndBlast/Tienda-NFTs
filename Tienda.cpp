#include <iostream>	// Terminal printing
#include <fstream>	// Files reading
#include <clocale>	// Terminal printing language
#include <string>	// String support
#include <cstdlib>	// Execute system()

#include "Disco.h"
#include "Libro.h"
#include "Pelicula.h"
#include "Arreglo.h"

using namespace std;

void readData();
void writeData();
int menu(const string title, const string options[], int numOptions);
int mainMenu();
int adminMenu();
int clientMenu();
int addProductMenu();
void catalogoMenu();
void addDisk();
void addBook();
void addMovie();
void buyProductMenu();

const string storeName = "NTF's";
Arreglo <Disco> discos = Arreglo<Disco>();
Arreglo <Libro> libros = Arreglo<Libro>();
Arreglo <Pelicula> peliculas = Arreglo<Pelicula>();

int main() {
	int opt = -1;

	setlocale(LC_CTYPE, "Spanish");	// Permite imprimir acentos

	readData();		// Leer los productos de los archivos csv

	while (opt != 0) {
		opt = mainMenu();
		if (opt == 1) {			// Menu Administrador
			while (opt > 0) {
				opt = adminMenu();
				if (opt == 1) {			// Mostrar catalogo
					catalogoMenu();
					system("pause");
				}
				else if (opt == 2) {	// Mostrar añadir productos
					opt = addProductMenu();
					if (opt == 1) {			// Añadir disco
						addDisk();
					}
					else if (opt == 2) {	// Añadir libro
						addBook();
					}
					else if (opt == 3) {	// Añadir pelicula
						addMovie();
					}
					else
						opt = -1;	// Regresar al menu anterior

					writeData();	// Sobreescribe con los datos agregados

					system("cls");
				}
				else
					opt = -1;	// Regresar al menu anterior
				system("cls");
			}
		}
		else if (opt == 2) {	// Menu Cliente
			while (opt>0) {
				opt = clientMenu();
				if (opt == 1) {			// Mostrar catalogo
					catalogoMenu();
					system("pause");
				}
				else if (opt == 2) {	// Mostrar comprar productos
					if (discos.size()+libros.size()+peliculas.size()) {	// Si hay productos, entonces permite entrar al menu de compra
						buyProductMenu();
						writeData();	// Sobreescribe con los datos agregados
					}
					else {
						cout << "No hay ningun producto en el inventario" << endl;
						system("pause");
					}

				}
				else
					opt = -1;	// Regresar al menu anterior
				system("cls");
			}
		}
	}
	return 0;
}

void readData() {
	string s;
	string del(",");		// archivo delimitados por comas (,)
	ifstream fDiscos("discos.csv");
	if (fDiscos.is_open()) {
		getline(fDiscos, s);

		while (!fDiscos.eof()) {
			Arreglo<string> results = Arreglo<string>();

			int start = 0;
			int end = s.find(del);
			while (end != -1) {	// Leer los elementos separados por comas
				results.push(s.substr(start, end - start));
				start = end + del.size();
				end = s.find(del, start);
			}
			results.push(s.substr(start, end - start));

			discos.push(Disco(
				stof(results.at(1)),
				stof(results.at(2)),
				results.at(0),
				results.at(3),
				results.at(4),
				results.at(5),
				stoi(results.at(6))
			));
				
			getline(fDiscos, s);
		}
	}
	else
		cerr << "Sin inventario de discos." << endl;

	ifstream fLibros("libros.csv");
	if (fLibros.is_open()) {
		getline(fLibros, s);

		while (!fLibros.eof()) {
			Arreglo<string> results = Arreglo<string>();

			int start = 0;
			int end = s.find(del);
			while (end != -1) {
				results.push(s.substr(start, end - start));
				start = end + del.size();
				end = s.find(del, start);
			}
			results.push(s.substr(start, end - start));

			libros.push(Libro(
				stof(results.at(1)),
				stof(results.at(2)),
				results.at(0),
				results.at(3),
				results.at(4),
				results.at(5),
				results.at(6),
				stoi(results.at(7))
			));

			getline(fLibros, s);
		}
	}
	else
		cerr << "Sin inventario de libros." << endl;

	ifstream fPeliculas("peliculas.csv");
	if (fPeliculas.is_open()) {
		getline(fPeliculas, s);

		while (!fPeliculas.eof()) {
			Arreglo<string> results = Arreglo<string>();

			int start = 0;
			int end = s.find(del);
			while (end != -1) {
				results.push(s.substr(start, end - start));
				start = end + del.size();
				end = s.find(del, start);
			}
			results.push(s.substr(start, end - start));

			peliculas.push(Pelicula(
				stof(results.at(1)),
				stof(results.at(2)),
				results.at(0),
				results.at(3),
				stoi(results.at(4)),
				results.at(5)
			));

			getline(fPeliculas, s);
		}
	}
	else
		cerr << "Sin inventario de peliculas." << endl;
}

void writeData() {
	ofstream fLibros("libros.csv");
	if (fLibros.is_open()) {
		for (int i=0; i<libros.size(); i++) {
			Libro libro = libros.at(i);
			fLibros << libro.getNombre() << ",";
			fLibros << libro.getPrecio() << ",";
			fLibros << libro.getDescuento() << ",";
			fLibros << libro.getTipo() << ",";
			fLibros << libro.getAutor() << ",";
			fLibros << libro.getEditoria() << ",";
			fLibros << libro.getEdicion() << ",";
			fLibros << libro.getNoPaginas() << endl;
		}
	}
	else cerr << "Error al abrir libros.csv." << endl;

	ofstream fDiscos("discos.csv");
	if (fDiscos.is_open()) {
		for (int i=0; i<discos.size(); i++) {
			Disco disco = discos.at(i);
			fDiscos << disco.getNombre() << ",";
			fDiscos << disco.getPrecio() << ",";
			fDiscos << disco.getDescuento() << ",";
			fDiscos << disco.getTipo() << ",";
			fDiscos << disco.getArtista() << ",";
			fDiscos << disco.getDisquera() << ",";
			fDiscos << disco.getNoCanciones() << endl;
		}
	}
	else cerr << "Error al abrir discos.csv." << endl;

	ofstream fPeliculas("peliculas.csv");
	if (fPeliculas.is_open()) {
		for (int i=0; i<peliculas.size(); i++) {
			Pelicula pelicula = peliculas.at(i);
			fPeliculas << pelicula.getNombre() << ",";
			fPeliculas << pelicula.getPrecio() << ",";
			fPeliculas << pelicula.getDescuento() << ",";
			fPeliculas << pelicula.getTipo() << ",";
			fPeliculas << pelicula.getDuracion() << ",";
			fPeliculas << pelicula.getClasificacion() << endl;
		}
	}
	else cerr << "Error al abrir peliculas.csv." << endl;
}


int menu(const string title, const string options[], int numOptions) {
	int choose = -1,
		isValid = 0;
	system("cls");

	while (!isValid) {	// Ciclo de validacion
		cout << title << endl;

		for (int i=0; i<numOptions; i++)	// Imprimi Opciones
			cout << i+1 << ". " << options[i] << endl;
		cout << "0. Regresar " << endl;

		cin >> choose;
		isValid = choose>=0 && choose<=numOptions;

		system("cls");

		if (!isValid)
			cout << "\tElige una opción válida" << endl << endl;
	}

	cin.ignore(numeric_limits<int>::max(), '\n');	// Limpiar buffer de entrada para que funcione correctamente getline()

	return choose;
}
int mainMenu() {
	const string options[] = { "Soy Administrador", "Soy Cliente" };
	
	return menu("Menu Inicial", options, 2);
}
int adminMenu() {
	const string options[] = { "Mostrar catálogo de los productos", "Añadir productos" };

	return menu("Menu Administrador", options, 2);
}
int clientMenu() {
	const string options[] = { "Mostrar catálogo de los productos", "Comprar productos" };

	return menu("Menu Cliente", options, 2);
}

int addProductMenu() {
	const string options[] = { "Disco", "Libro", "Pelicula" };

	return menu("Tipo de producto a añadir:", options, 3);
}

void addDisk() {
	Arreglo<string> atributos = Arreglo<string>();
	string s;
	cout << "Nombre: ";
	getline(cin, s);
	atributos.push(s);
	cout << "Precio: ";
	getline(cin, s);
	atributos.push(s);
	cout << "Descuento: ";
	getline(cin, s);
	atributos.push(s);
	cout << "Artista: ";
	getline(cin, s);
	atributos.push(s);
	cout << "Disquera: ";
	getline(cin, s);
	atributos.push(s);
	cout << "No. Canciones: ";
	getline(cin, s);
	atributos.push(s);

	discos.push( Disco (
		stof(atributos.at(1)),
		stof(atributos.at(2)),
		atributos.at(0),
		"disco",
		atributos.at(3),
		atributos.at(4),
		stoi(atributos.at(5))
	));
}
void addBook() {
	Arreglo<string> atributos = Arreglo<string>();
	string s;
	cout << "Nombre: ";
	getline(cin, s);
	atributos.push(s);
	cout << "Precio: ";
	getline(cin, s);
	atributos.push(s);
	cout << "Descuento: ";
	getline(cin, s);
	atributos.push(s);
	cout << "Autor: ";
	getline(cin, s);
	atributos.push(s);
	cout << "Editorial: ";
	getline(cin, s);
	atributos.push(s);
	cout << "Edicion: ";
	getline(cin, s);
	atributos.push(s);
	cout << "No. Páginas: ";
	getline(cin, s);
	atributos.push(s);

	libros.push( Libro (
		stof(atributos.at(1)),
		stof(atributos.at(2)),
		atributos.at(0),
		"libro",
		atributos.at(3),
		atributos.at(4),
		atributos.at(5),
		stoi(atributos.at(6))
	));
}
void addMovie() {
	Arreglo<string> atributos = Arreglo<string>();
	string s;
	cout << "Nombre: ";
	getline(cin, s);
	atributos.push(s);
	cout << "Precio: ";
	getline(cin, s);
	atributos.push(s);
	cout << "Descuento: ";
	getline(cin, s);
	atributos.push(s);
	cout << "Duración: ";
	getline(cin, s);
	atributos.push(s);
	cout << "Clasificacion: ";
	getline(cin, s);
	atributos.push(s);

	peliculas.push( Pelicula (
		stof(atributos.at(1)),
		stof(atributos.at(2)),
		atributos.at(0),
		"pelicula",
		stoi(atributos.at(3)),
		atributos.at(4)
	));
}

void buyProductMenu() {
	string repeat = "s";
	double cuenta = 0;

	while (repeat == "s") {
		int id = -1, cantidad = 0;
		repeat = "";

		catalogoMenu();

		cin.ignore(numeric_limits<int>::max(), '\n');	// Limpiar buffer de entrada para que funcione correctamente getline()
		while (id<=0 || id>(discos.size()+libros.size()+peliculas.size())) {
			cout << endl << "\tIngresa el ID del producto que vas a comprar: ";
			cin >> id;

			if (id<=0)
				cout << "\t\tIngresa un valor positivo" << endl;
			else if (id > (discos.size() + libros.size() + peliculas.size()))	// Valida que no elija un ID donde no hay un producto
				cout << "\t\tIngresa un ID disponible" << endl;
		}
		cin.ignore(numeric_limits<int>::max(), '\n');	// Limpiar buffer de entrada para que funcione correctamente getline()
		while (cantidad<=0) {
			cout << "\tCantidad que llevarás: ";
			cin >> cantidad;
			if (cantidad <= 0)
				cout << "\t\tIngresa un valor válido" << endl;
		}
		--id;	// Corregir el id

		if (id < libros.size()) {		// Seleccionó un ID de Libros
			cuenta += libros.at(id).getPrecio()* (1-libros.at(id).getDescuento()) * cantidad;
			libros.del(id);
		}
		else {
			id -= libros.size();
			if (id < discos.size()) {	// Seleccionó un ID de Discos
				cuenta += discos.at(id).getPrecio() * (1-discos.at(id).getDescuento()) * cantidad;
				discos.del(id);
			}
			else {							// Seleccionó un ID de Peliculas
				id -= discos.size();

				cuenta += peliculas.at(id).getPrecio() * (1-peliculas.at(id).getDescuento()) * cantidad;
				peliculas.del(id);
			}
		}
		cin.ignore(numeric_limits<int>::max(), '\n');	// Limpiar buffer de entrada para que funcione correctamente getline()

		while (repeat != "s" && repeat != "n") {
			cout << "\t¿Deseas seguir comprando? s/n: ";
			getline(cin, repeat);
			if (repeat != "s" && repeat != "n")
				cout << "\t\tIngresa solamente 's' o 'n'" << endl;
		}
		if (repeat == "s")
			system("cls");
	}

	cout << "\tCantidad a pagar:\t$" << cuenta << endl;
	system("pause");
}

void catalogoMenu() {
	int idx = 0;
	cout << "Tienda " << storeName << " - Catálogo" << endl;
	if (libros.size()) {	// Imprime solamente libros si hay productos
		cout << endl << "Libros" << endl;
		cout << "ID\t" << Libro::getAttributes() << endl;
		for (int i = 0; i < libros.size(); i++) {
			Libro libro = libros.at(i);
			cout << ++idx << "\t";
			cout << libro.getNombre() << "\t";
			cout << libro.getPrecio() << "\t";
			cout << libro.getDescuento() << "\t";
			cout << libro.getAutor() << "\t";
			cout << libro.getEditoria() << "\t";
			cout << libro.getEdicion() << "\t";
			cout << libro.getNoPaginas() << endl;
		}
	}

	if (discos.size()) {	// Imprime solamente discos si hay productos
		cout << endl << "Discos" << endl;
		cout << "ID\t" << Disco::getAttributes() << endl;
		for (int i = 0; i < discos.size(); i++) {
			Disco disco = discos.at(i);
			cout << ++idx << "\t";
			cout << disco.getNombre() << "\t";
			cout << disco.getPrecio() << "\t";
			cout << disco.getDescuento() << "\t";
			cout << disco.getArtista() << "\t";
			cout << disco.getDisquera() << "\t";
			cout << disco.getNoCanciones() << endl;
		}
	}

	if (peliculas.size()) {	// Imprime solamente peliculas si hay productos
		cout << endl << "Peliculas" << endl;
		cout << "ID\t" << Pelicula::getAttributes() << endl;
		for (int i = 0; i < peliculas.size(); i++) {
			Pelicula pelicula = peliculas.at(i);
			cout << ++idx << "\t";
			cout << pelicula.getNombre() << "\t";
			cout << pelicula.getPrecio() << "\t";
			cout << pelicula.getDescuento() << "\t";
			cout << pelicula.getDuracion() << "\t";
			cout << pelicula.getClasificacion() << endl;
		}
	}
}