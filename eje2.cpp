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
	
	void agregarInicio(int valor) {
		Nodo* nuevo = new Nodo(valor);
		if (inicio == nullptr) {
			inicio = fin = nuevo;
		} else {
			nuevo->setSiguiente(inicio);
			inicio = nuevo;
		}
		cantidad++;
	}
	
	void eliminarInicio() {
		if (inicio != nullptr) {
			Nodo* borrado = inicio;
			inicio = inicio->getSiguiente();
			delete borrado;
			cantidad--;
			if (inicio == nullptr)
				fin = nullptr;
		}
	}
	
	int getCantidad() {
		return cantidad;
	}
	
	void mostrar() {
		Nodo* i = inicio;
		while (i != nullptr) {
			cout << i->getDato() << " ";
			i = i->getSiguiente();
		}
		cout << endl;
	}
};

int main() {
	Lista l;
	
	l.agregarFinal(8);
	l.agregarInicio(18);
	l.agregarFinal(5);
	l.agregarFinal(34);
	l.agregarFinal(12);
	l.mostrar();
	
	cout << "Cantidad actual: " << l.getCantidad() << endl;
	
	l.eliminarInicio();
	l.mostrar();
	cout << "Cantidad actual: " << l.getCantidad() << endl;
	
	return 0;
}