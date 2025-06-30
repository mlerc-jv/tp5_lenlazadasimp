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
            cout << "Pila vacía" << endl;
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

    p.pushStack(10);
    p.pushStack(20);
    p.pushStack(30);

    cout << "Contenido de la pila: ";
    p.mostrar(); 

    cout << "Tope: " << p.topStack() << endl;

    p.popStack();
    cout << "Despues de pop: ";
    p.mostrar(); 

    cout << "¿Esta vacia?: " << (p.isEmptyStack() ? "si" : "no") << endl;
    cout << "¿Esta llena?: " << (p.isFullStack() ? "si" : "no") << endl;

    return 0;
}