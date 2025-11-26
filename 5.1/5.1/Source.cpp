
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (FXX) de los autores de la solución.
 *Mónica Martín Ramírez F48
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;


/*@ <answer>

Queremos el camino minimo asi que usamos recorrido en anchura (cola), lo vamos creando segun lo recorremos

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
int resolver(int ini, int fin) {
	if (ini == fin)return 0; //no hay calculos
	queue<int> digitos;
	vector<int> dist(10000,-1);
	dist[ini] = 0;
	digitos.push(ini);
	while (!digitos.empty()) {
		int num = digitos.front();
		digitos.pop();

		int o1 = (num + 1) % 10000;
		int o2 = (num * 2) % 10000;
		int o3 = num/3;

		for (int n : {o1, o2, o3}) {
			if (dist[n] == -1) { //si aun no he llegado a el
				dist[n] = dist[num]+1; //la distancia se actualiza
				if (n == fin)return dist[num] +1 ; //si estoy en el q quiero
				digitos.push(n); //lo meto a la cola
			}
		}
	}
	return dist[fin];
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int ini, fin;
	cin >> ini >> fin;
	if (!std::cin)  // fin de la entrada
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	cout<<resolver(ini, fin)<<endl;
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
