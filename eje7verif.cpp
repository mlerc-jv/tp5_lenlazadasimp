#include <iostream>
using namespace std;

class Nodo {
private:
	int dato;
	Nodo* siguiente;
public:
	Nodo(int d) {
		dato = d;
		siguiente = nullptr;
	}
	
	int getDato() { return dato; }
	Nodo* getSiguiente() { return siguiente; }
	void setSiguiente(Nodo* s) { siguiente = s; }
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
			Nodo* actual = inicio;
			while (actual->getSiguiente() != nullptr) {
				actual = actual->getSiguiente();
			}
			actual->setSiguiente(nuevo);
		}
	}
	
	Nodo* getInicio() {
		return inicio;
	}
	
	void mostrar() {
		Nodo* actual = inicio;
		cout << "Lista: ";
		while (actual != nullptr) {
			cout << actual->getDato() << " ";
			actual = actual->getSiguiente();
		}
		cout << "NULL" << endl;
	}
};



void enigma(Nodo* nodo) {
	if (nodo != nullptr) {
		if (nodo->getSiguiente() == nullptr)
			cout << nodo->getDato() << endl;
		else {
			enigma(nodo->getSiguiente());
			cout << nodo->getDato() << endl;
		}
	}
}

int misterio(Nodo* nodo) {
	if (nodo == nullptr)
		return 0;
	else
		return misterio(nodo->getSiguiente()) + 1;
}

Nodo* desconocido(Nodo* nodo) {
	if (nodo == nullptr || nodo->getSiguiente() == nullptr)
		return nodo;
	else
		return desconocido(nodo->getSiguiente());
}



int main() {
	Lista l;
	
	
	l.agregarFinal(6);
	l.agregarFinal(4);
	l.agregarFinal(9);
	l.agregarFinal(5);
	l.agregarFinal(8);
	
	l.mostrar();
	
	cout << "Prueba de enigma: "<<endl;
	enigma(l.getInicio());
	
	cout << "Prueba de misterio "<<endl;
	int cantidad = misterio(l.getInicio());
	cout << "cantidad de nodos: " << cantidad << endl; 
	
	cout << "Prueba de desconocido "<<endl;
	Nodo* ultimo = desconocido(l.getInicio());
	if (ultimo != nullptr)
		cout << "ultimo nodo contiene: " << ultimo->getDato() << endl; 
	
	return 0;
}