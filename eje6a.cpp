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
            while (actual->getSiguiente() != nullptr)
                actual = actual->getSiguiente();
            actual->setSiguiente(nuevo);
        }
    }

    bool esPrimo(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int contarPrimos() {
        Nodo* actual = inicio;
        int contador = 0;
        while (actual != nullptr) {
            if (esPrimo(actual->getDato()))
                contador++;
            actual = actual->getSiguiente();
        }
        return contador;
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

    l.agregarFinal(7);
    l.agregarFinal(10);
    l.agregarFinal(13);
    l.agregarFinal(26);
    l.agregarFinal(29);
    l.agregarFinal(17);

    l.mostrar();

    int cantidadPrimos = l.contarPrimos();
    cout << "cantidad de numeros primos: " << cantidadPrimos << endl;

    return 0;
}