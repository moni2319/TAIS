
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (FXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <limits>
#include <vector>

using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

template <typename T>
class Dijkstra {
	private:
		const T INF = numeric_limits<T>::max();
		vector<AristaDirigida<T>> ultima;
		vector<T> dist;
		IndexPQ<T> pq;
		vector<int> caminos;

	public:
		Dijkstra(DigrafoValorado<T> const & g): ultima(g.V()), dist(g.V(), INF), pq(g.V()),caminos(g.V(),0){
			dist[0] = 0;
			caminos[0] = 1;
			pq.push(0, 0);
			while (!pq.empty()) {
				int v = pq.top().elem;
				pq.pop();
				for (auto a : g.ady(v)) {
					int v1 = a.desde(), w = a.hasta();
					if (dist[w] > dist[v1] + a.valor()) {
						dist[w] = dist[v1] + a.valor();
						ultima[w] = a;
						caminos[w] = caminos[v1];
						pq.update(w, dist[w]);
					}
					else if (dist[w] == dist[v1] + a.valor())caminos[w] += caminos[v1];
				}
			}
		}

		int getcaminos()
		{
			return caminos[caminos.size() - 1];
		}

};

bool resuelveCaso() {
	// leer los datos de la entrada
	int N, A;
	cin >> N;
	if (!std::cin)  // fin de la entrada
		return false;
	cin >> A;
	DigrafoValorado<int> g(N);
	int v, w, dist;
	for (int i = 0; i < A; i++) {
		cin >> v >> w >> dist;
		g.ponArista({ v - 1,w - 1,dist });
		g.ponArista({ w - 1,v - 1,dist });
	}
	Dijkstra<int>sol(g);
	// resolver el caso posiblemente llamando a otras funciones
	cout<<sol.getcaminos()<<endl;
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
