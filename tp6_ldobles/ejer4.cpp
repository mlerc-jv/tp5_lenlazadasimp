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
	cout << "Lista: ";
	pnodo i = lista.inicio;
	while (i != NULL) {
		cout << i->dato << " ";
		i = i->sig;
		}
		cout << endl;
	}
void MostrarMayMen(tlista lista) {
	if (lista.inicio == NULL) {
		cout << "lista vacia" << endl;
		return;
	}
	
	int mayor = lista.inicio->dato;
	int menor = lista.inicio->dato;
	pnodo actual = lista.inicio->sig;
	
	while (actual != NULL) {
		if (actual->dato > mayor)
			mayor = actual->dato;
		if (actual->dato < menor)
			menor = actual->dato;
		actual = actual->sig;
	}
	
	cout << "Mayor: " << mayor << endl;
	cout << "Menor: " << menor << endl;
}

int main() {
	tlista lista;
	pnodo nuevo;
	IniciarLista(lista);
	
	CrearNodo(nuevo, 546); AgregarFinal(lista, nuevo);
	CrearNodo(nuevo, 823);  AgregarFinal(lista, nuevo);
	CrearNodo(nuevo, 357); AgregarFinal(lista, nuevo);
	CrearNodo(nuevo, 445);  AgregarFinal(lista, nuevo);
	
	MostrarLista(lista);
	MostrarMayMen(lista);
	
	return 0;
}