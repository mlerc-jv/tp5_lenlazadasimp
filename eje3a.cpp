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
	
	int buscarindice(int valor) {
		Nodo* actual = inicio;
		int indice = 0;
		while (actual != nullptr) {
			if (actual->getDato() == valor)
				return indice;
			actual = actual->getSiguiente();
			indice++;
		}
		return -1;
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

l.agregarFinal(17);
l.agregarFinal(23);
l.agregarFinal(12);
l.agregarFinal(99);
l.mostrar();

cout << "indice de numero 12: " << l.buscarindice(12) << endl;
cout << "indice de numero 45: " << l.buscarindice(45) << endl;
 return 0;

}