#pragma once

#include <iostream>
using namespace std;

template <class TipoDato>

class Arreglo {
	private:
		TipoDato* elementos;
		int numeroElementos;
	public:

		Arreglo() {
			numeroElementos = 0;
		}

		~Arreglo() {
			delete[] elementos;
		}

		int size()
			{ return numeroElementos; }

		TipoDato at(int indice) 
			{ return elementos[indice]; }

		void put(TipoDato elemento, int indice) {
			if (indice >= numeroElementos) {
				TipoDato* nuevosElementos = new TipoDato[indice + 1];
				for (int i = 0; i < numeroElementos; i++)
					nuevosElementos[i] = elementos[i];
				elementos = nuevosElementos;
			}
			elementos[indice] = elemento;
			numeroElementos = indice + 1;
		}

		void push(TipoDato elemento) {
			TipoDato* nuevosElementos = new TipoDato[numeroElementos + 1];
			for (int i = 0; i < numeroElementos; i++)
				nuevosElementos[i] = elementos[i];
			elementos = nuevosElementos;

			elementos[numeroElementos] = elemento;
			numeroElementos = numeroElementos + 1;
		}

		void del(int indice) { // Metodo para borrar 
			if (indice < numeroElementos) {
				TipoDato* nuevosElementos = new TipoDato[--numeroElementos];
				for (int i = 0; i < numeroElementos; i++)
					// Se ignora el indice seccionado
					if (i < indice)
						nuevosElementos[i] = elementos[i];
					else if (i > indice)
						nuevosElementos[i-1] = elementos[i-1];
				elementos = nuevosElementos;
			}
		}
};