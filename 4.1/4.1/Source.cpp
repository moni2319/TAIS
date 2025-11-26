
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (FXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool dfs(const Grafo& g, int v, int padre, std::vector<bool>& visitado, bool& hayCiclo, int& visitados) {
	visitado[v] = true; //el primer nodo lo he visitado
	++visitados; //esto me sirve para saber si es conexo

	for (int w : g.ady(v)) {
		if (!visitado[w]) { //no lo he visitado
			if (dfs(g, w, v, visitado, hayCiclo, visitados))
				return true;
		}
		else if (w != padre) { //como es el mismo hay un ciclo
			hayCiclo = true;
			return true;
		}
	}

	return false;
}

bool esArbol(const Grafo& g) {
	std::vector<bool> visitado(g.V(), false);
	bool hayCiclo = false;
	int visitados = 0;

	dfs(g, 0, -1, visitado, hayCiclo, visitados);

	bool esConexo = (visitados == g.V());

	return esConexo && !hayCiclo;
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int v, a;
	cin >> v >> a;
	if (!std::cin)  // fin de la entrada
		return false;
	Grafo g(v);
	for (int i = 0; i < a; i++) {
		int a, b;
		cin >> a >> b;
		g.ponArista(a, b);
	}
	// resolver el caso posiblemente llamando a otras funciones
	if (esArbol(g))cout << "SI" << endl;
	else cout << "NO" << endl;
	// escribir la solución

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Texto.txt");
	if (!in.is_open())
		std::cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout << "Pulsa Intro para salir..." << std::flush;
	std::cin.get();
#endif
	return 0;
}
