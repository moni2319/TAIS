
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

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

Es como el de la calculadora solo que no me importa si visito el nodo dos veces


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
int resolver(int& a, int& b, const Digrafo& g) {
	queue<int> visitados;
	vector<int> dist(g.V(), -1);
	visitados.push(a);
	dist[a] = 0;
	while (!visitados.empty()) {
		int v = visitados.front();
		visitados.pop();

		for (int n : g.ady(v) ){
			if (dist[n] == -1) { //por cada uno de los adyacentes
				dist[n] = dist[v]+1;
				if(n == b)return dist[n]+1;
				visitados.push(n); // ya lo he visitado
			}
		}
	}
	return dist[b];
}
bool resuelveCaso() {
	// leer los datos de la entrada
	int restaurantes, calles;
	cin >> restaurantes >> calles;
	if (!std::cin)  // fin de la entrada
		return false;
	Digrafo g(restaurantes);
	for (int i = 0; i < calles; i++) {
		int a, b;
		cin >> a >> b;
		g.ponArista(a + 1, b + 1);
	}
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) {
		int a, b;
		cin >> a >> b;
		int v = resolver(a, b, g);
		if (v == 0)cout << "Imposible" << endl;
		else cout << v << endl;
	}
	// resolver el caso posiblemente llamando a otras funciones

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
