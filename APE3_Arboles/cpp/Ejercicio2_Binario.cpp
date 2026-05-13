#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

Nodo* insertar(Nodo* raiz, int valor) {
    // TODO: Implementa tu lógica aquí
    // SOLUCIÓN: Si llegamos a un lugar vacío, creamos el nuevo nodo ahí.
    // Si el valor es menor vamos a la izquierda, si es mayor o igual a la derecha.
    // Reasignamos el puntero del hijo para enlazar correctamente el nuevo nodo.
    if (raiz == nullptr) return new Nodo(valor);
    if (valor < raiz->valor)
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    else
        raiz->derecho = insertar(raiz->derecho, valor);
    return raiz;
}

int main() {
    Nodo* raiz = new Nodo(10);
    
    // CORRECCIÓN: insertar() devuelve el nodo raíz actualizado; hay que reasignarlo.
    raiz = insertar(raiz, 5);
    raiz = insertar(raiz, 15);
    raiz = insertar(raiz, 3);
    
    cout << "--- Prueba Ejercicio 2 ---" << endl;
    cout << "Raiz (Esperado 10): " << raiz->valor << endl;
    
    if(raiz->izquierdo) cout << "Hijo Izquierdo (Esperado 5): " << raiz->izquierdo->valor << endl;
    else cout << "Hijo Izquierdo: null" << endl;
    
    if(raiz->derecho) cout << "Hijo Derecho (Esperado 15): " << raiz->derecho->valor << endl;
    else cout << "Hijo Derecho: null" << endl;
    
    if(raiz->izquierdo && raiz->izquierdo->izquierdo) 
        cout << "Hijo Izq del 5 (Esperado 3): " << raiz->izquierdo->izquierdo->valor << endl;
    else cout << "Hijo Izq del 5: null" << endl;

    return 0;
}