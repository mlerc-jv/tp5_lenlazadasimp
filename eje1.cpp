#include <iostream>
using namespace std;

class Nodo {
private:
	int dato;
	Nodo* sig;
public:
	Nodo(int dato) {
		this->dato = dato;
		this->sig = nullptr;
	}
	
	int getDato() { return dato; }
	Nodo* getSiguiente() { return sig; }
	void setSiguiente(Nodo* s) { sig = s; }
};

class Lista {
private:
	Nodo* inicio;
public:
	Lista() {
		inicio = nullptr;
	}
	
	void agregarFinal(int valor) {
		Nodo* nuevo = new Nodo(valor);
		if (inicio == nullptr) {
			inicio = nuevo;
		} else {
			Nodo* i = inicio;
			while (i->getSiguiente() != nullptr)
				i = i->getSiguiente();
			i->setSiguiente(nuevo);
		}
	}
	
	int minimo() {
		if (inicio == nullptr) {
			cout << "Lista vacia" << endl;
			return -1;
		}
		int min = inicio->getDato();
		Nodo* i = inicio->getSiguiente();
		while (i != nullptr) {
			if (i->getDato() < min)
				min = i->getDato();
			i = i->getSiguiente();
		}
		return min;
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
	l.agregarFinal(5);
	l.agregarFinal(56);
	l.agregarFinal(2);
	l.agregarFinal(4);
	l.agregarFinal(67);
	
	l.mostrar();
	cout << "Minimo: " << l.minimo() << endl;
	
	return 0;
}