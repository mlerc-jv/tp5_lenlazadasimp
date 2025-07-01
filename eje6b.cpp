#include <iostream>
using namespace std;

class Nodo {
private:
    char dato;
    Nodo* siguiente;
public:
    Nodo(char d) {
        dato = d;
        siguiente = nullptr;
    }

    char getDato() { return dato; }
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

    void agregarFinal(char valor) {
        Nodo* nuevo = new Nodo(valor);
        if (inicio == nullptr) {
            inicio = nuevo;
        } else {
            Nodo* actual = inicio;
            while (actual->getSiguiente() != nullptr)
                actual = actual->getSiguiente();
            actual->setSiguiente(nuevo);
        }
    }

    void contarMayusMinus(int& mayus, int& minus) {
        mayus = 0;
        minus = 0;
        Nodo* actual = inicio;
        while (actual != nullptr) {
            char c = actual->getDato();
            if (c >= 'A' && c <= 'Z')
                mayus++;
            else if (c >= 'a' && c <= 'z')
                minus++;
            actual = actual->getSiguiente();
        }
    }

    void mostrar() {
        Nodo* actual = inicio;
        cout << "Lista de caracteres: ";
        while (actual != nullptr) {
            cout << actual->getDato() << " ";
            actual = actual->getSiguiente();
        }
        cout << endl;
    }
};

int main() {
    Lista l;

    l.agregarFinal('Z');
    l.agregarFinal('u');
    l.agregarFinal('a');
    l.agregarFinal('5');
    l.agregarFinal('W');
    l.agregarFinal('P');
    l.agregarFinal('r'); 

    l.mostrar();

    int mayusculas, minusculas;
    l.contarMayusMinus(mayusculas, minusculas);

    cout << "cantidad de mayus: " << mayusculas << endl;
    cout << "cantidad de minus: " << minusculas << endl;

    return 0;
}