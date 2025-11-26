#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

#include "DigrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

template <typename T>
class Dijkstra {
private:
    IndexPQ<T> pq;
    vector<T> dist;
    int tam;

    void relajar(AristaDirigida<T> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            pq.update(w, dist[w]);
        }
    }

public:
    Dijkstra(DigrafoValorado<T> const& g, int salida)
        : dist(g.V(), numeric_limits<T>::max() / 4), pq(g.V()), tam(g.V())
    {
        dist[salida] = 0;
        pq.push(salida, 0);

        while (!pq.empty()) {
            int v = pq.top().elem;
            pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }

    void getDistances(int tiempo, int salida) {
        int contador = 0;
        for (int i = 0; i < tam; i++)
            if (i != salida && dist[i] <= tiempo) // ignorar la salida
                contador++;
        cout << contador << endl;
    }

};

bool resuelveCaso() {
    int N, S, T, P;
    cin >> N >> S >> T >> P;
    if (!cin) return false;

    DigrafoValorado<int> g(N);
    for (int i = 0; i < P; i++) {
        int u, v, tiempo;
        cin >> u >> v >> tiempo;
        g.ponArista({ v - 1, u - 1, tiempo }); // transponer
    }

    Dijkstra<int> d(g, S - 1);
    d.getDistances(T,S-1);

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    if (!in.is_open()) std::cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout << "Pulsa Intro para salir..." << std::flush;
    std::cin.get();
#endif
    return 0;
}

