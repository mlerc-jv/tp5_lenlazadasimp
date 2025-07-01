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
    void setDato(int d) { dato = d; }
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

    void ordenarSeleccion() {
        Nodo* i = inicio;
        while (i != nullptr) {
            Nodo* min = i;
            Nodo* j = i->getSiguiente();
            while (j != nullptr) {
                if (j->getDato() < min->getDato()) {
                    min = j;
                }
                j = j->getSiguiente();
            }
            
            int temp = i->getDato();
            i->setDato(min->getDato());
            min->setDato(temp);

            i = i->getSiguiente();
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
};

int main() {
    Lista l;

    l.agregarFinal(5);
    l.agregarFinal(2);
    l.agregarFinal(19);
    l.agregarFinal(36);
    l.agregarFinal(6);

    cout << "Lista original:" << endl;
    l.mostrar();

    l.ordenarSeleccion();

    cout << "Lista ordenada por seleccion:" << endl;
    l.mostrar();

    return 0;
}