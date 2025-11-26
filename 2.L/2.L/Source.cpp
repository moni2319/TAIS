
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
// propios o los de las estructuras de datos de clase
struct tAtril {
	int musicosOg;
	int partituras;
	int actu;
};
struct cmp {
	bool operator()(const tAtril a, const tAtril b){
		return a.actu < b.actu;
	}
};

bool resuelveCaso() {
	// leer los datos de la entrada
	int p, n, x;
	cin >> p >> n;
	if (!std::cin)  // fin de la entrada
		return false;
	
	// resolver el caso posiblemente llamando a otras funciones
	priority_queue<tAtril, vector<tAtril>, cmp>pq;
	for (int i = 0; i < n; i++) {
		cin >> x;
		pq.push({ x,1,x});
	}
	for (int i = n; i < p; i++) {
		tAtril prim = pq.top();
		prim.partituras++;
		prim.actu = (prim.musicosOg+prim.partituras -1) / prim.partituras;
		pq.pop();
		pq.push(prim);
	}
	cout << pq.top().actu << endl;
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
