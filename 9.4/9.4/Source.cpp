// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;
/*
TEST DE FACTIBILIDAD:

    Una solución parcial es factible si ninguna silla supera el peso maximo indicado;
    

ESTRATEGIA VORAZ:

    Ordenamos los pesos de menor a mayor.
    en cada paso intentamos emparejar el menor peso con el mayor sin superar el limite, 
    aprovechado al maximo cada silla;

FUNCIÓN DE SELECCIÓN:

    Entre los restantes seleccionamos al más pesado, si es factible, los emparejamos, si no,
    el de mayor peso viaja solo;

TEST DE SOLUCIÓN:

    La estrategia es óptima porque cada vez que avanzamos el peso lo máximo posible,
    evitamos dejar huecos y minimizamos el número de telesillas necesarios.
    Si en algún paso no existe una suma menor que el peso maximo,
    entonces comprobamos con la siguiente.

FUNCIÓN OBJETIVO:

    Minimizar el número de telesillas que pesan como maximo el peso maximo dado en el enunciado
    garantizando que no quede ningún pasajero sin subir al telesilla.
*/

// función que resuelve el problema
int resolver(const vector<int> & v, int& pMax) {
    int beneficio = 0, ini = 0, fin = v.size() - 1;
    while (ini <= fin) {
        if (v[ini] + v[fin] <= pMax) {
            ini++; // se emparejan
        }
        fin--;
        beneficio++;
    }
    return beneficio;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int pMax, n;
    cin >> pMax >> n;
    if (!std::cin)
        return false;
    vector<int> v(n);
    for (int& x : v)cin >> x;
    sort(v.begin(), v.end());
    cout<<resolver(v, pMax)<<endl;

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