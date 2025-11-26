// Mónica Martín
// TAIS F24
/*

TEST SOLUCION

    he cubierto todos los agujeros

TEST FACTIBILIDAD

    
    
FUNCION SELECCION

    dist[a] - dist[b] > l

FUNCION OBJETIVO

    el numero de parches que compra es el minimo posible
    
ESTRATEGIA VORAZ

    no compro mas si no hace falta
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int> & posiciones, int l) {
    int sol = 0;
    int distCubierta = -1;
    for (int i = 0; i < posiciones.size();i++) {
        if (posiciones[i] > distCubierta)
        {
            sol++;
            distCubierta = posiciones[i] + l;
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, l;
    cin >> n >> l;
    if (!std::cin)
        return false;
    vector<int> posiciones(n);
    for (int& x : posiciones) {
        cin >> x;
    }
    cout << resolver(posiciones, l)<<endl;

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