
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (FXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct tCaja {
	int tiempo_en_libre;
	int numero;
};
struct cmp {
	bool operator()(const tCaja& a, const tCaja& b) {
		if (a.tiempo_en_libre == b.tiempo_en_libre)
			return a.numero > b.numero;
		return a.tiempo_en_libre > b.tiempo_en_libre;
	}
};
bool resuelveCaso() {
	// leer los datos de la entrada
	int N, C;
	cin >> N >> C;
	if (N==0 && C==0)
		return false;
	//LEO LOS CLIENTES PRIMERO
	vector<int> clientes(C);
	for (int& x : clientes) {
		cin >> x;
	}

	//RELLENO LA COLA DE PRIORIDAD
	priority_queue<tCaja, vector<tCaja>, cmp>pq;
	int i = 0;
	// Asignamos un cliente por cada caja hasta que se acaben los clientes
	for (; i < N && i < C; i++) {
		pq.push({ clientes[i], i + 1 });
	}
	// Si sobran cajas vacías, las agregamos con tiempo 0
	if (C < N) {
		for (int j = C; j < N; j++) {
			pq.push({ 0, j + 1 });
		}
	}
	//ASIGNO LOS CLIENTES QUE ME FALTAN
	for (; i < C; i++) {
		tCaja prim = pq.top();
		pq.pop();
		prim.tiempo_en_libre += clientes[i];
		pq.push(prim);
	}
	
	cout << pq.top().numero << endl;
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
