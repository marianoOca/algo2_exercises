#include<string>

using namespace std;

// Ejercicio 1: Pasar a templates
template<class T>
T cuadrado(T x) {
  return x * x;
}

// Ejercicio 2: Pasar a templates
template<class Contenedor, class Elem>
bool contiene(Contenedor s, Elem c) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == c) return true;
  }
  return false;
}

// Ejercicio 3: Funcion es prefijo con un template contenedor
template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){ //a es prefijo de b
    if (a.size() >= b.size()) return false;
    for (int i = 0; i < a.size();  i++){
       if (a[i] != b[i]) return false;
    }
    return true;
}

// Ejercicio 4: Función maximo con un template contenedor y uno elemento
template<class Contenedor, class Elem>
Elem maximo(Contenedor c){
    int res = 0;
    for (int i = 1; i < c.size(); i++){
        if (c[res] < c[i]) res = i;
    }
    return c[res];
}

/*
#ifndef TUPLA_HPP
#define TUPLA_HPP

template<class T1, class T2>
class Tupla {
public:
    Tupla(T1 t1, T2 t2);
    T1 t1() const;
    T2 t2() const;
private:
    T1 _t1;
    T2 _t2;
};

template<class T1, class T2>
Tupla<T1, T2>::Tupla(T1 t1, T2 t2): _t1(t1), _t2(t2) {}

#endif //*/