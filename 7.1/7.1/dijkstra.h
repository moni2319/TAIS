#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"
using namespace std;

template <typename T>
class Dijkstra {
private:
	const int INF = numeric_limits<int>::max();
	vector<int> ultima; //puede ser tambien una arista dirigida
	vector<T> dist;
	IndexPQ<T> pq;
	int origen;
	int destino;

	void relajar(AristaDirigida<T> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			ultima[w] = v;
			pq.update(w, dist[w]);
		}
	}
public:

	Dijkstra(DigrafoValorado<T> const& g, int origen, int destino) :
		dist(g.V(), INF),
		ultima(g.V(), -1),
		pq(g.V()),
		origen(origen),
		destino(destino) {


		dist[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem;
			pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}
	}

	int getDistance() { return dist[destino]; }

	void camino(int origen, int destino) {
		if (origen == destino) {
			cout << origen + 1;
			return;
		}
		else {
			camino(origen, ultima[destino]);
			cout << " -> " << destino + 1;
		}
	}

};
#endif DIJKSTRA_H_
