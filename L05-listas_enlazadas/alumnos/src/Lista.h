#ifndef _LISTA_ALUMNOS_H_
#define _LISTA_ALUMNOS_H_

#include <string>
#include <ostream>

using namespace std;

typedef unsigned long Nat;

class Lista {
public:

    Lista();                                // Constructor por defecto de la clase Lista.

    Lista(const Lista& l);                  // Constructor por copia de la clase Lista.

    ~Lista();                               // Destructor de la clase Lista.

    Lista &operator=(const Lista& aCopiar); // Operador asignacion

    void agregarAdelante(const int& elem);  // Agrega un elemento al principio de la Lista.

    void agregarAtras(const int& elem);     // Agrega un elemento al final de la Lista.

    void eliminar(Nat i);                   // Elimina el i-ésimo elemento de la Lista.

    int longitud() const;                   // Devuelve la cantidad de elementos que contiene la Lista.

    const int& iesimo(Nat i) const;         // Devuelve el elemento en la i-ésima posición de la Lista
                                            // como referencia NO modificable

    int& iesimo(Nat i);                     // Devuelve el elemento en la i-ésima posición de la Lista
                                            // como referencia modificable

    void mostrar(ostream& o);               // Muestra la lista en un ostream: [a_0, a_1, a_2, ...]

    friend ostream& operator<<(ostream& os, Lista& l) {
        l.mostrar(os);
        return os;
    }

    void borrar();

private:

    struct Nodo {
        Nodo(const int& elem);
        int data_;
        Nodo*sig;
        Nodo*ant;
    };

    int largo_;

    Nodo*prim;
    Nodo*ulti;
};


#include "Lista.hpp"

#endif