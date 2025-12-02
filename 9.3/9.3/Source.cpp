// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
/*
TEST DE FACTIBILIDAD:

    Una solución parcial es factible si la suma del voltaje de las
    pilas seleccionadas alcanzan el V min


ESTRATEGIA VORAZ:

    Ordenamos las pilas por su voltaje de menor a mayor.
    en cada paso seleccionamos entre los extremos cuya suma sea >= V min,
    así avanzamos lo minimo en cada solucion, maximizando el numero de coches.

FUNCIÓN DE SELECCIÓN:

    Entre todo par de pilas, a y b, se escoge el que de la menor suma posible y que supere 
    la V min,

TEST DE SOLUCIÓN:

    La estrategia es óptima porque cada vez que avanzamos lo minimo posible,
    maximizando asi el numero de coches que se pueden usar.
    Si en algún paso no existe un par de pilas que sumen lo minimo,
    se avanza el inicio del intervalo para garantizar que siempre se usa el minimo posible

FUNCIÓN OBJETIVO:

    Maximizar el par de pilas que suman V min, para maximizar el numero de coches
*/

using namespace std;
// función que resuelve el problema
int resolver(vector<int> &pilas, int&v) {
    int beneficio = 0, ini = 0, fin = pilas.size() - 1;
    while (ini < fin) {
        if (pilas[fin] + pilas[ini] >= v) {
            beneficio++;
            fin--;
            ini++;
        }
        else if (pilas[fin] + pilas[ini] < v) {
            ini++;
        }
    }
    return beneficio;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, v;
    cin >> n>> v;
    vector<int>pilas(n);
    for (int& x : pilas)cin >> x;
    sort(pilas.begin(), pilas.end()); //ordena de menor a mayor
    cout<<resolver(pilas,v)<<endl;
    // escribir sol
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}