
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (FXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */




void dfs(Digrafo const& g,int v , vector<bool> &visitados, vector<bool> &apilado, vector<int> &ant, bool &ciclo) { //detectar 
	apilado[v] = true;
	visitados[v] = true;

	for (int w : g.ady(v)) {
		if (ciclo)return;
		if (!visitados[w]) {
			ant[w] = v;
			dfs(g, w, visitados, apilado, ant, ciclo);
		}
		else if (apilado[w])ciclo = true;
	}
	apilado[v] = false;
	
}

void p(Digrafo const& g, int v, vector<bool>& visitados) {
	visitados[v] = true;
	for (int w : g.ady(v))
		if (!visitados[w]) {
			p(g, w, visitados);
		}

}

bool resuelveCaso() {
	// leer los datos de la entrada
	int l;
	cin >> l;
	if (!std::cin)  // fin de la entrada
		return false;
	Digrafo g(l+1);
	for (int i = 0; i < l; ++i) {
		string tipo;
		cin >> tipo;
		if (tipo == "A") {
			g.ponArista(i, i + 1);
		}
		else if (tipo == "J") {
			int salto;
			cin >> salto;
			g.ponArista(i, salto-1);
		}
		else if (tipo == "C") {
			int salto;
			cin >> salto;
			g.ponArista(i, salto-1);
			g.ponArista(i, i + 1);
		}
	}
	vector<bool> visitados(g.V(), false);
	vector<bool> apilado(g.V(), false);
	vector<int> ant(g.V(), -1);
	bool ciclo = false;
	dfs(g, 0, visitados, apilado, ant, ciclo);
	visitados.assign(g.V(), false);
	p(g, 0, visitados);


	if (ciclo) {
		if (visitados[l]) cout << "A VECES" << endl;
		else cout << "NUNCA" << endl;
	}
	else cout << "SIEMPRE" << endl;
	


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
