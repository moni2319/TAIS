// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>


using namespace std;
// función que resuelve el problema
/*
TEST FACTIBILIDAD:

    se realizan todas las tareas en sus respectivos plazos, es correcta solo si es admisible

ESTRATEGIA VORAZ:

    edificios de menro a mayor extremo oriental

FUNCION SELECCION: 

    seleccionamos el que tenga el extremo or

TEST SOLUCION:

    

FUNCION OBJETIVO:

    

*/

struct tSol {
    int occidental;
    int oriental;
};
bool operator<(tSol& a, tSol& b) {
    return a.oriental < b.oriental;
}

int resolver(vector<tSol> & edificios) {
    int beneficio = 0, n = edificios.size(), i = 0;
    int ultimo = -1;
    sort(edificios.begin(), edificios.end());

    while (i < n) {
        if (edificios[i].occidental >= ultimo) {
            beneficio++;
            ultimo = edificios[i].oriental;
        }
        i++;
    }
    return beneficio;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a, b;

    cin >> n;
    if (n == 0)
        return false;
    vector<tSol>v(n);
    for (int i = 0; i < n;i++) {
        cin >> a >> b;
        v[i] = { a,b };
    }
    cout<<resolver(v)<<endl;

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
