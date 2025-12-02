// Mónica Martín Ramírez
// F24


#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

/*
TEST FACTIBILIDAD:

    es factible si las tareas seleccionadas cubren sin huecos el intervalo dado,
    si no existe un conjunto de tareas que lo cumplan la soucion es invalida

ESTRATEGIA VORAZ:

    ordenamos las tareas por su inicio de menor a mayor,
    seleccionamos en cada paso aquellas que tienen un inicio <=pos
    y escogemos aquella cuya final sea el maximo entre el actual y el suyo propio,
    asi conseguimos siempre avanzar lo maximo

FUNCION SELECCION:

    entre todos los intervalos seleccionamos el que tenga mayor extremo final

TEST SOLUCION:

    la estrategia es optima ya que cada vez avanzamos lo maximo posible sin dejar huecos, minimizando
    el numero de tareas necesarias

FUNCION OBJETIVO:

    minimizar el numero de tareas necesarias para cubrir un intervalo[c,f), garantizando que no 
    quedan huecos libres

*/
using namespace std;
// función que resuelve el problema
struct tSol {
    int ini;
    int fin;
};

bool operator<(tSol& a, tSol& b) {
    return a.ini < b.ini;
}

int resolver(vector<tSol> & tareas,const int& c,const int& f) {
    sort(tareas.begin(), tareas.end());
    int n = tareas.size(), final = -1, beneficio = 0, pos = c,i=0;
    while (pos < f) {
        int mejorFinal = pos;
        while (i < n && tareas[i].ini <= pos) {
            mejorFinal = max(mejorFinal, tareas[i].fin);
            i++;
        }
        if (mejorFinal == pos)return -1;
        beneficio++;
        pos = mejorFinal;
    }
    return beneficio;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, c, f, ini, fin;
    cin >> c>>f>>n;
    if (n == 0 && c== 0 && f==0)
        return false;
    vector<tSol>v(n);
    for (int i = 0; i < n; i++) {
        cin >> ini >> fin;
        v[i] = { ini,fin };
    }
    int sol = resolver(v, c, f);
    if (sol == -1) cout << "Imposible\n";
    else cout << sol << "\n";

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
