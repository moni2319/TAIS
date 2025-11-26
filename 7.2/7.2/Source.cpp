
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <vector>
#include <limits>
#include <fstream>

using namespace std;

#include "DigrafoValorado.h" 
#include "IndexPQ.h" 


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
template <typename Valor>
class Dijkstra {
    private:
        const Valor INF = numeric_limits<Valor>::max(); // al principio todas las distancias origen -> nodo x seran INF
        vector<AristaDirigida<Valor>> ultima; //guarda la ultima arista usada para cacular la ruta corta
        vector<Valor> dist; //distancia minima conocida de origen -> nodo x
        IndexPQ<Valor> pq; //cola de prioridad que saca siempre el nodo con la distancia mas pequeña
        vector<int> coste_min; 
        int tam;

        void relajar(AristaDirigida<Valor> a) {
            int v = a.desde(), w = a.hasta(); //sacamos los nodos origen y direccion
            if (dist[w] > dist[v] + a.valor() + coste_min[w]) { //existe un camino mas corto?
                dist[w] = dist[v] + a.valor() + coste_min[w]; //actualizamos la distancia minima
                ultima[w] = a; //guardamos la arista usada
                pq.update(w, dist[w]); //actualizamos la cola 
            }
        }

    public:
        Dijkstra(DigrafoValorado<Valor> const& g, vector<int> const& coste) : //parametros
            dist(g.V(), INF), 
            ultima(g.V()), 
            pq(g.V()), 
            tam(g.V()), 
            coste_min(coste){ //lista de inicializacion

            dist[0] = coste_min[0];
            pq.push(0, coste_min[0]);
            while (!pq.empty()) {
                int v = pq.top().elem;
                pq.pop();
                for (auto a : g.ady(v))
                    relajar(a);
            }
        }
        int tiempo_min() {
            return dist[tam - 1] != INF ? dist[tam - 1] : -1;
        }

};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;

    vector<int> coste_individual(N);

    for (int i = 0; i < N; i++)
        cin >> coste_individual[i];

    DigrafoValorado<int> digrafo(N);

    int A, v, w, valor;
    cin >> A;

    for (int i = 0; i < A; i++)
    {
        cin >> v >> w >> valor;
        digrafo.ponArista({ v - 1, w - 1, valor });
    }

    Dijkstra<int> sol(digrafo, coste_individual);

    if (sol.tiempo_min() == -1)
        cout << "IMPOSIBLE";
    else
        cout << sol.tiempo_min();
    cout << "\n";

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
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}