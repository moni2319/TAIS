// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;
/*
TEST SOLUCION

    Si ya he comprobado todas las camisetas y todos los jugadores

TEST FACTIBILIDAD

    el maximo de jugadores con camiseta antigua

FUNCION OBJETIVO

    maximizar el numero de jugadores con camiseta

FUNCION SELECCION

    Cogemos las tallas mas grandes las primeras, tanto de las equipaciones como de los jugadores

ESTRATEGIA VORAZ

    La reparto si hace falta

*/

// función que resuelve el problema
int resolver(const vector<int>& jugadores, const vector<int>& equipaciones) {
    int sol = 0;
    int j = 0,i=0;
    bool repartido = false;
    while(i<jugadores.size() && !repartido) { //no pasa nada si se quedan camisetas sin repartir, por eso comparo con los jugadores
        if (jugadores[i] == equipaciones[j] || jugadores[i] + 1 == equipaciones[j]) { //si le viene
            j++;
            i++;
            sol++;
        }
        else if (equipaciones[j] > jugadores[i]+1) { //si la equipacion es mas grande
            j++;
        }
        else if (equipaciones[j] < jugadores[i]) { //si la equipacion es mas pequeña
            i++;
        }
        if (j == equipaciones.size()) {
            repartido = true;
        }
    }
    return jugadores.size()-sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    cin >> n >> m;
    if (!std::cin)
        return false;
    vector<int> jugadores(n);
    for (int& x : jugadores) cin >> x;
    vector<int> equipaciones(m);
    for (int& x : equipaciones) cin >> x;
    sort(equipaciones.begin(),equipaciones.end(), greater<int>());
    sort(jugadores.begin(), jugadores.end(), greater<int>());

    cout<<resolver(jugadores,equipaciones)<<endl;

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