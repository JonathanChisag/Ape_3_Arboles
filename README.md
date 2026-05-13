# 🌳 APE3 — Árboles | Estructura de Datos

> **Universidad Técnica de Ambato**  
> Facultad de Ingeniería en Sistemas, Electrónica e Industrial  
> Carrera de Software · Ciclo Enero – Julio 2026

---

## 📋 Descripción

Práctica de laboratorio sobre estructuras de datos de tipo **árbol**, implementada en **C++** y **Java**. 
Se desarrollaron cinco ejercicios que cubren operaciones fundamentales sobre árboles N-arios y árboles binarios de búsqueda (BST).

---

## ⚙️ Cómo compilar y ejecutar

### C++
```bash
g++ -o e1 Ejercicio1_Basico.cpp && ./e1
g++ -o e2 Ejercicio2_Binario.cpp && ./e2
g++ -o e3 Ejercicio3_Binario.cpp && ./e3
g++ -o e4 Ejercicio4_Recorridos.cpp && ./e4
g++ -o e5 Ejercicio5_Transformacion.cpp && ./e5
```

### Java
```bash
javac Ejercicio1_Basico.java && java Ejercicio1_Basico
javac Ejercicio2_Binario.java && java Ejercicio2_Binario
javac Ejercicio2_Binario.java Ejercicio3_Binario2.java && java Ejercicio3_Binario2
javac Ejercicio2_Binario.java RecorridoInOrder.java && java RecorridoInOrder
javac Ejercicio2_Binario.java Ejercicio5_Transformacion.java && java Ejercicio5_Transformacion
```

---

## 🧩 Ejercicios implementados

### Ejercicio 1 — Contar Nodos en un Árbol N-ario (`contarNodos`)

Se implementó una función recursiva que cuenta el total de nodos de un árbol donde cada nodo puede tener múltiples hijos.

**Estrategia:** Se eligió recursividad porque el árbol N-ario es una estructura naturalmente recursiva: cada hijo es a su vez la raíz de un subárbol independiente.

- **Caso base:** si el puntero al nodo es `null`, no existe nodo que contar → retorna `0`. Esto detiene la recursión cuando se agotan los hijos de una rama.
- **Caso recursivo:** se inicializa un contador en `1` (el nodo actual) y se itera sobre cada hijo, acumulando el resultado de llamar a `contarNodos` en cada subárbol.
- Cuando todas las llamadas retornan, el acumulador contiene el conteo completo del árbol con raíz en ese nodo.
- Resultado esperado: 6

---

### Ejercicio 2 — Inserción en un BST (`insertar`)

Se implementó la inserción recursiva en un Árbol Binario de Búsqueda respetando la propiedad: valores menores a la izquierda, mayores o iguales a la derecha.

**Estrategia:** La inserción explota la propiedad de ordenamiento del BST para ubicar el lugar correcto sin comparar con todos los nodos.

- **Caso base:** si el nodo actual es `null`, se encontró el lugar vacío correcto → se crea el nuevo nodo y se retorna para que el llamador lo enlace.
- **Caso recursivo:** se compara el valor a insertar con el nodo actual. Si es menor, se delega al subárbol izquierdo; si es mayor o igual, al derecho. Se **reasigna el puntero del hijo**
- con el resultado de la llamada recursiva para que el nuevo nodo quede correctamente enlazado.
- **Corrección aplicada:** el `main` original llamaba `insertar(raiz, valor)` sin reasignar el retorno, por lo que los hijos nunca se enlazaban. Se corrigió a `raiz = insertar(raiz, valor)`.
Resultado esperado: Raíz=10 | Izq=5 | Der=15 | Izq del 5=3

---

### Ejercicio 3 — Altura de un Árbol Binario (`calcularAltura`)

Se implementó una función recursiva que retorna la profundidad máxima de un árbol binario.

**Estrategia:** La altura es una propiedad que se define recursivamente sobre la estructura del árbol, lo que hace que la recursividad sea la estrategia natural.

- **Caso base:** un árbol vacío (nodo `null`) tiene altura `0`. Esto también cubre los nodos hoja: sus hijos son `null`, la siguiente llamada retorna `0`.
- **Caso recursivo:** la altura de un nodo es `1` (el propio nodo) más la mayor entre la altura de su subárbol izquierdo y la de su subárbol derecho. Se usa `max`
- para seleccionar el camino más largo, garantizando que se contabilice la rama más profunda del árbol.
Resultado esperado: altura = 3

---

### Ejercicio 4 — Recorrido In-Order (`inOrderAux`)

Se implementó el recorrido **izquierdo → raíz → derecho** que acumula los valores visitados en una lista.

**Estrategia:** El recorrido In-Order tiene la propiedad de visitar los nodos de un BST en orden ascendente, siendo útil para listar elementos de forma ordenada.

- **Caso base:** si el nodo es `null`, no hay nada que visitar → se retorna inmediatamente. Detiene la recursión en hojas y subárboles vacíos.
- **Caso recursivo:** primero se recorre recursivamente el subárbol **izquierdo** (todos los menores), luego se agrega el **valor del nodo actual**
- a la lista de resultados, y finalmente el subárbol **derecho** (todos los mayores). Al completar todas las llamadas, la lista contiene los valores en orden ascendente.
Resultado esperado: 1 2 3 4 5 6 7

---

### Ejercicio 5 — Invertir un Árbol Binario (`invertir`)

Se implementó una función recursiva que produce el espejo de un árbol binario intercambiando los hijos izquierdo y derecho de cada nodo.

**Estrategia:** Invertir un árbol actúa de forma idéntica en cada nodo (intercambiar sus hijos), lo que se expresa de manera natural con recursividad.

- **Caso base:** si el nodo es `null`, no hay nada que invertir → se retorna `null`. Cubre tanto árboles vacíos como el final de las ramas.
- **Caso recursivo:** se guarda el hijo izquierdo en un **temporal**, se asigna al hijo izquierdo la **versión invertida del subárbol derecho**
- (llamada recursiva), y al hijo derecho la **versión invertida del temporal**. El intercambio ocurre de abajo hacia arriba:
- primero se invierten los subárboles hijos y luego se intercambian, garantizando que toda la estructura quede en espejo al terminar la recursión en la raíz.
Resultado esperado: Izq=3 | Der=2
