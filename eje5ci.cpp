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

    void combinarCon(Lista& otra) {
        Nodo* actual = otra.inicio;
        while (actual != nullptr) {
            this->agregarFinal(actual->getDato());
            actual = actual->getSiguiente();
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
    Lista luno, ldos;

    luno.agregarFinal(3);
    luno.agregarFinal(7);
    luno.agregarFinal(9);

    ldos.agregarFinal(5);
    ldos.agregarFinal(8);
    ldos.agregarFinal(11);

    cout << "lista uno: ";
    luno.mostrar();

    cout << "Lista dos: ";
    ldos.mostrar();

    luno.combinarCon(ldos);

    cout << "Lista combinada sin orden: ";
    luno.mostrar();

    return 0;
}