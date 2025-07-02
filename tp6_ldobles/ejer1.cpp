#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo {
	int dato;
	pnodo sig;
	pnodo ant;
} tnodo;

void IniciarLista(pnodo &inicio) {
	inicio = NULL;
}

void CrearNodo(pnodo &nuevo, int valor) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->sig = NULL;
		nuevo->ant = NULL;
	}
}

void AgregarInicio(pnodo &inicio, pnodo nuevo) {
	if (inicio == NULL) {
		inicio = nuevo;
	} else {
		nuevo->sig = inicio;
		inicio->ant = nuevo;
		inicio = nuevo;
	}
}

void AgregarFinal(pnodo &inicio, pnodo nuevo) {
	pnodo i;
	if (inicio == NULL) {
		inicio = nuevo;
	} else {
		for (i = inicio; i->sig != NULL; i = i->sig);
		i->sig = nuevo;
		nuevo->ant = i;
	}
}

void AgregarOrden(pnodo &inicio, pnodo nuevo) {
	pnodo i;
	if (inicio == NULL) {
		inicio = nuevo;
	} else {
		if (nuevo->dato < inicio->dato) {
			nuevo->sig = inicio;
			inicio->ant = nuevo;
			inicio = nuevo;
		} else {
			for (i = inicio; i->sig != NULL && (i->sig)->dato < nuevo->dato; i = i->sig);
			if (i->sig != NULL) {
				nuevo->sig = i->sig;
				nuevo->ant = i;
				(i->sig)->ant = nuevo;
				i->sig = nuevo;
			} else {
				i->sig = nuevo;
				nuevo->ant = i;
			}
		}
	}
}

pnodo QuitarInicio(pnodo &inicio) {
	pnodo extraido;
	if (inicio == NULL) {
		extraido = NULL;
	} else {
		if (inicio->sig == NULL) {
			extraido = inicio;
			inicio = NULL;
		} else {
			extraido = inicio;
			inicio = inicio->sig;
			inicio->ant = NULL;
			extraido->sig = NULL;
		}
	}
	return extraido;
}

pnodo QuitarFinal(pnodo &inicio) {
	pnodo extraido, i;
	if (inicio == NULL) {
		extraido = NULL;
	} else {
		for (i = inicio; i->sig != NULL; i = i->sig);
		extraido = i;
		if (i->ant != NULL)
			(i->ant)->sig = NULL;
		else
			inicio = NULL;
		i->ant = NULL;
	}
	return extraido;
}

pnodo QuitarNodo(pnodo &inicio, int valor) {
	pnodo extraido, i;
	if (inicio == NULL) {
		extraido = NULL;
	} else {
		if (inicio->dato == valor) {
			extraido = inicio;
			inicio = inicio->sig;
			if (inicio != NULL) inicio->ant = NULL;
			extraido->sig = NULL;
		} else {
			for (i = inicio; i != NULL && i->dato != valor; i = i->sig);
			if (i != NULL) {
				extraido = i;
				if (i->ant != NULL) (i->ant)->sig = i->sig;
				if (i->sig != NULL) (i->sig)->ant = i->ant;
				extraido->sig = NULL;
				extraido->ant = NULL;
			} else {
				extraido = NULL;
			}
		}
	}
	return extraido;
}

pnodo Buscar(pnodo inicio, int valor) {
	pnodo i = inicio;
	while (i != NULL) {
		if (i->dato == valor)
			return i;
		i = i->sig;
	}
	return NULL;
}

void MostrarLista(pnodo inicio) {
	pnodo i;
	if (inicio != NULL) {
		for (i = inicio; i != NULL; i = i->sig) {
			cout << i->dato << " ";
		}
		cout << endl;
	} else {
		cout << "Lista vacía" << endl;
	}
}
int main() {
	pnodo lista;
	pnodo nuevo;
	
	IniciarLista(lista); 
	
	CrearNodo(nuevo, 371); AgregarOrden(lista, nuevo);
	CrearNodo(nuevo, 539);  AgregarOrden(lista, nuevo);
	CrearNodo(nuevo, 723); AgregarOrden(lista, nuevo);
	CrearNodo(nuevo, 281); AgregarOrden(lista, nuevo);
	
	cout << "Lista ordenada actual (f): "<<endl;
	MostrarLista(lista);
	
	CrearNodo(nuevo, 695);
	AgregarInicio(lista, nuevo);
	cout << "agregar al inicio (d): "<<endl;
	MostrarLista(lista);
	

	CrearNodo(nuevo, 468);
	AgregarFinal(lista, nuevo);
	cout << "Agregar al final (e): "<<endl;
	MostrarLista(lista);
	
	pnodo buscado = Buscar(lista, 723);
	cout << "Buscar el valor 723 (j): "<<endl;
	if (buscado != NULL)
		cout << "Encontrado: " << buscado->dato << endl;
	else
		cout << "Valor no encontrado." << endl;
	
	pnodo extraido = QuitarNodo(lista, 281);
	cout << "Quitar el nodo con valor 281 (i): "<<endl;
	MostrarLista(lista);
	

	extraido = QuitarInicio(lista);
	cout << "Quitar el inicio (g): "<<endl;
	MostrarLista(lista);
	
	extraido = QuitarFinal(lista);
	cout << "Quitar al final (h): "<<endl;
	MostrarLista(lista);
	
	return 0;
}