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

    static Lista combinarOrdenado(Lista& a, Lista& b) {
        Lista nueva;
        Nodo* p1 = a.inicio;
        Nodo* p2 = b.inicio;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->getDato() <= p2->getDato()) {
                nueva.agregarFinal(p1->getDato());
                p1 = p1->getSiguiente();
            } else {
                nueva.agregarFinal(p2->getDato());
                p2 = p2->getSiguiente();
            }
        }

        while (p1 != nullptr) {
            nueva.agregarFinal(p1->getDato());
            p1 = p1->getSiguiente();
        }

        while (p2 != nullptr) {
            nueva.agregarFinal(p2->getDato());
            p2 = p2->getSiguiente();
        }

        return nueva;
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

    luno.agregarFinal(5);
    luno.agregarFinal(8);
    luno.agregarFinal(15);

    ldos.agregarFinal(7);
    ldos.agregarFinal(9);
    ldos.agregarFinal(23);

    cout << "Lista uno: ";
    luno.mostrar();

    cout << "Lista dos: ";
    ldos.mostrar();

    Lista combinada = Lista::combinarOrdenado(luno, ldos);

    cout << "lista combinada ordenada: ";
    combinada.mostrar();

    return 0;
}