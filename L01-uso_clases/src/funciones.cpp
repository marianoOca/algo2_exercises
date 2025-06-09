#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
bool pertenece( int a, vector<int> v ){
    bool res = false;

    for(int i : v) res = res || (i == a);

    return res;
}

vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res {};

    for(int i : s){
        if(!pertenece(i, res)) res.push_back(i);
    }

    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> res {};

    for(int i : s) if(res.count(i) == 0) res.insert(i);

    //return res;
    return quitar_repetidos(s);
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    bool res = true;

    for(int i : a ) res =  res && pertenece(i, b);

    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {

    return mismos_elementos(a, b);
}

// Ejercicio 5
int apariciones(int a, vector<int> v){
    int res = 0;

    for(int i : v) if(i == a) res++;

    return res;
}

map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> m;

    for(int i : s) m[i] = apariciones(i, s);

    return m;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res {};

    for(int i : s) if(apariciones(i, s) == 1) res.push_back(i);

    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res {};

    for(int i : a) if(b.count(i) == 1) res.insert(i);

    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> m;

    for(int i : s) m[i%10].insert(i);

    return m;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;

    for(char i : str){
        int l0 = res.size();

        for(int j = 0; j < tr.size() && res.size() == l0; j++)
            if(tr[j].first == i) res.push_back(tr[j].second);

        if(l0 == res.size()) res.push_back(i);
    }

    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    bool res = false;
    map<LU, set<LU>> gruposGuardados;

    for (Mail mail : s) {
        set<LU> grupoAsunto = mail.libretas();

        for (LU libreta : grupoAsunto) {
            if (gruposGuardados.count(libreta) == 0) {
                gruposGuardados[libreta] = grupoAsunto;
            } else {
                res = res || (gruposGuardados[libreta] != grupoAsunto);
            }
        }
    }

    return res;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> registro;

    for(Mail mail : s){
        if(mail.adjunto()){
            if( registro.count(mail.libretas()) == 0 ||
                mail.fecha() > registro[mail.libretas()].fecha() ){

                registro[mail.libretas()] = mail;
            }
        }
    }

    return registro;
}
