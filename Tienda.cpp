#include <iostream>
#include <clocale>

using namespace std;

int mainMenu();
int adminMenu();
int clientMenu();
int catalogueMenu();

const char* storeName = "NTF's";

int main() {
	mainMenu();
	return 0;
}


int menu(const char* title, const char* options[], int numOptions) {
	int choose = -1,
		isValid = 0;

	setlocale(LC_CTYPE, "Spanish");
	system("cls");

	while (!isValid) {
		cout << title << endl;

		for (int i=0; i<numOptions; i++)
			cout << i+1 << ". " << options[i] << endl;

		cin >> choose;
		isValid = choose>0 && choose<=numOptions;

		system("cls");

		if (!isValid)
			cout << "\tElige una opción válida" << endl << endl;
	}

	return choose;
}
int mainMenu() {
	const char* options[] = { "Soy Administrador", "Soy Cliente" };
	
	return menu("Menu Inicial", options, 2);
}
int adminMenu() {
	const char* options[] = { "Mostrar catálogo de los productos", "Añadir productos" };

	return menu("Menu Administrador", options, 2);
}
int clientMenu() {
	const char* options[] = { "Mostrar catálogo de los productos", "Comprar productos" };

	return menu("Menu Cliente", options, 2);
}

int catalogueMenu() {
	/*
	const char* options[] = { "Mostrar catálogo de los productos", "Comprar productos" };

	return menu("Menu Cliente", options, 2);
	*/
}