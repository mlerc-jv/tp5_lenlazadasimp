#include <iostream>
using namespace std;

class Nodo {
private:
	int dato;
	Nodo* sig;
public:
	Nodo(int d) {
		dato = d;
		sig = nullptr;
	}
	
	int getDato() { return dato; }
	Nodo* getSiguiente() { return sig; }
	void setSiguiente(Nodo* s) { sig = s; }
};

class Lista {
private:
	Nodo* inicio;
	Nodo* fin;
	int cantidad;
public:
	Lista() {
		inicio = fin = nullptr;
		cantidad = 0;
	}
	
	void agregarFinal(int valor) {
		Nodo* nuevo = new Nodo(valor);
		if (inicio == nullptr) {
			inicio = fin = nuevo;
		} else {
			fin->setSiguiente(nuevo);
			fin = nuevo;
		}
		cantidad++;
	}
	
	Nodo* buscarxindice(int posicion) {
		if (posicion < 0 || posicion >= cantidad)
			return nullptr;
		Nodo* actual = inicio;
		int i = 0;
		while (i < posicion) {
			actual = actual->getSiguiente();
			i++;
		}
		return actual;
	}
	
	void mostrar() {
		Nodo* i = inicio;
		while (i != nullptr) {
			cout << i->getDato() << " ";
			i = i->getSiguiente();
		}
		cout << endl;
	}
	
	int getCantidad() {
		return cantidad;
	}
};

int main() {
	Lista l;
	
    l.agregarFinal(55);
	l.agregarFinal(88);
	l.agregarFinal(12);
	l.agregarFinal(37);
	l.mostrar();

	Nodo* n = l.buscarxindice(2);
	if (n != nullptr)
		cout << "valor en posicion 2: " << n->getDato() << endl;
	else
		cout << "posicion invalida" << endl;

	return 0;
}