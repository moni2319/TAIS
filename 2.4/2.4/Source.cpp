
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

struct tPaciente {
    string nombre;
    int gravedad, orden;
};
struct cmp {
    bool operator()(const tPaciente a, const  tPaciente b) {
        if (a.gravedad == b.gravedad)
            return a.orden > b.orden;
        return a.gravedad < b.gravedad;
    }
};
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

bool resuelveCaso() {
    // leer los datos de la entrada
    int eventos, grav;
    string tipo, nombre;
    cin >> eventos;
    if (eventos == 0)
        return false;
    int orden = -1;
    priority_queue<tPaciente, vector<tPaciente>, cmp> pq;
    for (int i = 0; i < eventos; i++) {
        cin >> tipo;
        if (tipo == "A") { //Si atiendo quiere decir que elimino al prioritario
            cout << pq.top().nombre << endl;
            pq.pop();
        }
        else if (tipo == "I") { //si ingresa uno nuevo tendgo que reordenador en funcion de la prioridad
            cin >> nombre >> grav;
            pq.push({ nombre,grav,orden++ });
        }
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    cout << "---" << endl;
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
