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
    Nodo* fin;
public:
    Lista() {
        inicio = fin = nullptr;
    }

    void agregarFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (inicio == nullptr) {
            inicio = fin = nuevo;
        } else {
            fin->setSiguiente(nuevo);
            fin = nuevo;
        }
    }

    void mostrar() {
        Nodo* actual = inicio;
        cout << "Lista: ";
        while (actual != nullptr) {
            cout << actual->getDato() << " ";
            actual = actual->getSiguiente();
        }
        cout << endl;
    }

    Nodo* getInicio() {
        return inicio;
    }
};

int main() {
    Lista l;

    l.agregarFinal(17);
    l.agregarFinal(8);
    l.agregarFinal(23);
    l.agregarFinal(5);

    l.mostrar();  

    return 0;
}