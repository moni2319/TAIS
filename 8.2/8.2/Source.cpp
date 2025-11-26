// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>


using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& atacantes, const vector<int>& defensores) {
    int sol = 0;
    int j = 0;
    for (int i = 0; i < atacantes.size(); i++) {
        if (atacantes[i] <= defensores[j]) {
            sol++;
            j++;
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    vector<int> atacantes(n);
    for (int& x : atacantes)cin >> x;
    vector<int> defensores(n);
    for (int& x : defensores)cin >> x;

    sort(atacantes.begin(), atacantes.end(), greater<int>());
    sort(defensores.begin(), defensores.end(), greater<int>());

    cout << resolver(atacantes, defensores) << endl;

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