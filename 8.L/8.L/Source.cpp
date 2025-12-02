// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
struct tSala {
    int num;
    int fin;
};
// función que resuelve el problema
int resolver(const vector<pair<int,int>>& v, vector<tSala> &salas) {
    salas.push_back({1,v[0].second }); //meto la primera conf en la primera sala
    for (int i = 1; i < v.size(); i++) {
        if(v[i].first< salas[])
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    vector<pair<int,int>>v(n);
    for (int i = 0; i < n; i++) {
        pair<int, int> horas;
        int ini, fin;
        cin >> ini >> fin;
        horas.first = ini;
        horas.second = fin;
        v.push_back(horas);
    }
    vector<tSala> salas;
    cout<<resolver(v,salas)<<endl;
  
    cout << endl;
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
