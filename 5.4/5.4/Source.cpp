
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


bool resuelveCaso() {
	// leer los datos de la entrada
	int m, s, t, n;
	cin >> m >> s >> t;
	if (!std::cin)  // fin de la entrada
		return false;
	cin >> n;

	vector<pair<int, int>> operaciones(n); //vector con ops
	for (int i = 0; i < n; ++i) {
		cin >> operaciones[i].first >> operaciones[i].second;
	}
	vector<int> dist(m, -1); //distancia a cada sol
	queue<int> q; //cola de prioridad
	dist[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int x = q.front(); 
		q.pop();
		for (auto& op : operaciones) {
			int a = op.first;
			int b = op.second;
			int y = (a * x + b) % m;
			if (dist[y] == -1) { //si todavia no 
				dist[y] = dist[x] + 1;
				q.push(y);
			}
		}
	}

	cout << dist[t] << "\n";
	return true;
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
