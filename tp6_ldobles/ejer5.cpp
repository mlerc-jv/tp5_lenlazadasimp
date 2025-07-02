#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	int dato;
	pnodo sig;
	pnodo ant;
};
typedef struct tlista{
	pnodo inicio;
	pnodo fin;
};

void IniciarLista(tlista &lista)
{
	lista.inicio = NULL;
	lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor)
{
	nuevo = new tnodo;
	if(nuevo != NULL)
	{
		nuevo -> dato = valor;
		nuevo -> sig = NULL;
		nuevo -> ant = NULL;
	}
}

void AgregarInicio(tlista &lista, pnodo nuevo)
{
	if(lista.inicio == NULL){
		lista.inicio = nuevo;
		lista.fin = nuevo;
	}
	else{
		nuevo->sig = lista.inicio;
		lista.inicio->ant = nuevo;
		lista.inicio = nuevo;
	}
}

void AgregarFinal(tlista &lista, pnodo nuevo){
	if(lista.inicio == NULL){
		lista.inicio = nuevo;
		lista.fin = nuevo;
	}
	else{
		lista.fin->sig = nuevo;
		nuevo->ant = lista.fin;
		lista.fin = nuevo;
	}
}
	void MostrarLista(tlista lista) {
		cout << " ";
		pnodo i = lista.inicio;
		while (i != NULL) {
			cout << i->dato << " ";
			i = i->sig;
		}
		cout << endl;
	}
	void EliminarMultiplosDe3(tlista &lista) {
		pnodo actual = lista.inicio;
		while (actual != NULL) {
			pnodo siguiente = actual->sig;
			if (actual->dato % 3 == 0) {
				
				if (actual == lista.inicio && actual == lista.fin) {
					lista.inicio = lista.fin = NULL;
				}
				
				else if (actual == lista.inicio) {
					lista.inicio = actual->sig;
					lista.inicio->ant = NULL;
				}
				
				else if (actual == lista.fin) {
					lista.fin = actual->ant;
					lista.fin->sig = NULL;
				}
				
				else {
					actual->ant->sig = actual->sig;
					actual->sig->ant = actual->ant;
				}
				delete actual;
			}
			actual = siguiente;
		}
	}
	
	int main() {
		tlista lista;
		pnodo nuevo;
		IniciarLista(lista);
		
		CrearNodo(nuevo, 50);  AgregarFinal(lista, nuevo);
		CrearNodo(nuevo, 8);  AgregarFinal(lista, nuevo);
		CrearNodo(nuevo, 69); AgregarFinal(lista, nuevo);
		CrearNodo(nuevo, 22);  AgregarFinal(lista, nuevo);
		CrearNodo(nuevo, 71); AgregarFinal(lista, nuevo);
		CrearNodo(nuevo, 33);  AgregarFinal(lista, nuevo);
		CrearNodo(nuevo, 12);  AgregarFinal(lista, nuevo);
		CrearNodo(nuevo, 95);  AgregarFinal(lista, nuevo);
		
		cout << "Lista: ";
		MostrarLista(lista);
		
		EliminarMultiplosDe3(lista);
		
		cout << "Lista sin multiplos de 3: ";
		MostrarLista(lista);
		
		return 0;
	}