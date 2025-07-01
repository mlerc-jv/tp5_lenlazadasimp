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

class Cola {
private:
    Nodo* frente;
    Nodo* final;
    int cantidad;
public:
    void initQueue() {
        frente = final = nullptr;
        cantidad = 0;
    }

    void pushQueue(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (frente == nullptr) {
            frente = final = nuevo;
        } else {
            final->setSiguiente(nuevo);
            final = nuevo;
        }
        cantidad++;
    }

    void popQueue() {
        if (frente != nullptr) {
            Nodo* borrado = frente;
            frente = frente->getSiguiente();
            delete borrado;
            cantidad--;
            if (frente == nullptr)
                final = nullptr;
        }
    }

    bool isEmptyQueue() {
        return frente == nullptr;
    }

    bool isFullQueue() {
        return false; // lista dinámica, no se llena
    }

    int topQueue() {
        if (frente != nullptr)
            return frente->getDato();
        else {
            cout << "cola vacia" << endl;
            return -1;
        }
    }

    int bottomQueue() {
        if (final != nullptr)
            return final->getDato();
        else {
            cout << "cola vacia" << endl;
            return -1;
        }
    }

    int getCantidad() {
        return cantidad;
    }

    void mostrar() {
        Nodo* actual = frente;
        cout << "Cola: ";
        while (actual != nullptr) {
            cout << actual->getDato() << " ";
            actual = actual->getSiguiente();
        }
        cout << endl;
    }
};

int main() {
    Cola c;
    c.initQueue();

    c.pushQueue(81);
    c.pushQueue(92);
    c.pushQueue(33);
    c.mostrar();

    cout << "Frente: " << c.topQueue() << endl;    
    cout << "Final: " << c.bottomQueue() << endl;  

    c.popQueue();
    c.mostrar(); 

    cout << "esta vacia?: " << (c.isEmptyQueue() ? "si" : "no") << endl;
    cout << "Esta llena?: " << (c.isFullQueue() ? "si" : "no") << endl;
    cout << "cantidad: " << c.getCantidad() << endl;

    return 0;
}