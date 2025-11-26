
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (FXX) de los autores de la solución.
 * Mónica Martín Ramírez F48 
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

Usamos un DFS porque queremos el orden topologico de las tareas

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


void topologico(Digrafo &g) {
	int n = g.V();
	vector<int> gradoEntrada(n, 0);
	for (int v = 0; v < n; ++v) {
		for (int w : g.ady(v)) {
			gradoEntrada[w]++;
		}
	}
	priority_queue<int, vector<int>, greater<int>> q;

	// añadir nodos sin predecesores
	for (int i = 0; i < n; ++i) {
		if (gradoEntrada[i] == 0)
			q.push(i);
	}

	vector<int> orden;
	while (!q.empty()) {
		int v = q.top();
		q.pop();
		orden.push_back(v);

		for (int w : g.ady(v)) {
			gradoEntrada[w]--;
			if (gradoEntrada[w] == 0)q.push(w);
		}
	}

	if (orden.size() < n)cout << "Imposible";
	else {
		for (int i = 0; i < n; i++) {
			if (i > 0) cout << " ";
			cout << orden[i] + 1;
		}
	}
	cout << endl;
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int tareas, rel;
	cin >> tareas >> rel;
	if (!std::cin)  // fin de la entrada
		return false;
	Digrafo d(tareas);
	// leo el grafo con sus restricciones
	for (int i = 0; i < rel; i++) {
		int a, b;
		cin >> a >> b;
		d.ponArista(a-1, b-1);
	}
	topologico(d);
	//escribo la solucion
	
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
