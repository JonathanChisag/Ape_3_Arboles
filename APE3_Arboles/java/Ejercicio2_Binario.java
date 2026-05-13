class Nodo {
    int valor;
    Nodo izquierdo, derecho;
    Nodo(int valor) { this.valor = valor; }
}

public class Ejercicio2_Binario {
    public static Nodo insertar(Nodo raiz, int valor) {
        // TODO: Implementa tu lógica aquí
        // Recuerda: menores a la izquierda, mayores o iguales a la derecha.
        // SOLUCIÓN: Si llegamos a null, creamos el nodo en ese lugar.
        // Comparamos el valor para decidir si ir a izquierda o derecha, reasignando el hijo.
        if (raiz == null) return new Nodo(valor);
        if (valor < raiz.valor)
            raiz.izquierdo = insertar(raiz.izquierdo, valor);
        else
            raiz.derecho = insertar(raiz.derecho, valor);
        return raiz;
    }

    public static void main(String[] args) {
        Nodo raiz = new Nodo(10);
        
        // CORRECCIÓN: insertar() devuelve el nodo raíz actualizado; hay que reasignarlo.
        raiz = insertar(raiz, 5);
        raiz = insertar(raiz, 15);
        raiz = insertar(raiz, 3);
        
        System.out.println("--- Prueba Ejercicio 2 ---");
        System.out.println("Raiz (Esperado 10): " + raiz.valor);
        
        String izq = (raiz.izquierdo != null) ? String.valueOf(raiz.izquierdo.valor) : "null";
        System.out.println("Hijo Izquierdo de Raiz (Esperado 5): " + izq);
        
        String der = (raiz.derecho != null) ? String.valueOf(raiz.derecho.valor) : "null";
        System.out.println("Hijo Derecho de Raiz (Esperado 15): " + der);
        
        String izqIzq = (raiz.izquierdo != null && raiz.izquierdo.izquierdo != null) ? String.valueOf(raiz.izquierdo.izquierdo.valor) : "null";
        System.out.println("Hijo Izquierdo del 5 (Esperado 3): " + izqIzq);
    }
}
