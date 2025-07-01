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

class Pila {
private:
    Nodo* tope;
public:
    void initStack() {
        tope = nullptr;
    }

    void pushStack(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->setSiguiente(tope);
        tope = nuevo;
    }

    void popStack() {
        if (tope != nullptr) {
            Nodo* borrado = tope;
            tope = tope->getSiguiente();
            delete borrado;
        }
    }

    int topStack() {
        if (tope != nullptr)
            return tope->getDato();
        else {
            cout << "pila vacia" << endl;
            return -1;
        }
    }

    bool isEmptyStack() {
        return tope == nullptr;
    }

    bool isFullStack() {
        return false; 
    }

    void mostrar() {
        Nodo* actual = tope;
        while (actual != nullptr) {
            cout << actual->getDato() << " ";
            actual = actual->getSiguiente();
        }
        cout << endl;
    }
};

int main() {
    Pila p;
    p.initStack();

    p.pushStack(71);
    p.pushStack(42);
    p.pushStack(19);

    cout << "Contenido de la pila: ";
    p.mostrar(); 

    cout << "cima: " << p.topStack() << endl;

    p.popStack();
    cout << "despues de pop: ";
    p.mostrar(); 

    cout << "esta vacia?: " << (p.isEmptyStack() ? "si" : "no") << endl;
    cout << "esta llena?: " << (p.isFullStack() ? "si" : "no") << endl;

    return 0;
}