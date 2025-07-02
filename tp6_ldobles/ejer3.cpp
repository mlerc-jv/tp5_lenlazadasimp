#include<iostream>
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

	void DecimalABinario(tlista &lista, int numero) {
		pnodo nuevo;
		if (numero == 0) {
			CrearNodo(nuevo, 0);
			AgregarInicio(lista, nuevo);
		} else {
			while (numero > 0) {
				int bit = numero % 2;
				CrearNodo(nuevo, bit);
				AgregarInicio(lista, nuevo); 
				numero = numero / 2;
			}
		}
	}
	void MostrarBinario(tlista lista) {
		pnodo actual = lista.inicio;
		cout << "Binario: ";
		while (actual != NULL) {
			cout << actual->dato;
			actual = actual->sig;
		}
		cout << endl;
	}
	int main() {
		tlista binario;
		IniciarLista(binario);
		
		int numero;
		cout << "ingrese un num decimal: ";
		cin >> numero;
		
		DecimalABinario(binario, numero);
		MostrarBinario(binario);
		
		return 0;
	}