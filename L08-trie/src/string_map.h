#ifndef STRING_MAP_H_
#define STRING_MAP_H_

#include <string>

using namespace std;

template<typename T>
class string_map {
    public:
        string_map();                               // Construye un diccionario vacio.

        string_map(const string_map<T>& aCopiar);   // Construye un diccionario por copia.

        string_map& operator=(const string_map& d); // OPERADOR ASIGNACION

        ~string_map();                              // DESTRUCTOR

        void insert(const pair<string, T>& calve);  // Inserta un par clave, valor en el diccionario

        int count(const string &key) const;         // Devuelve la cantidad de apariciones de la clave (0 o 1).
                                                    // Sirve para identificar si una clave está definida o no.

        const T& at(const string& key) const;       // Dada una clave, devuelve su significado.
        T& at(const string& key);                   // PRE: La clave está definida.

        void erase(const string& key);              // Dada una clave, la borra del diccionario junto a su significado.
                                                    // PRE: La clave está definida.

        int size() const;                           // Devuelve cantidad de claves definidas

        bool empty() const;                         // devuelve true si no hay ningún elemento en el diccionario

        T &operator[](const string &key);           // Acceso o definición de pares clave/valor

    private:
        struct Nodo {
            Nodo();
            Nodo(T* d);
            vector<Nodo*> siguientes;
            T* def;
        };

        void  borrarNodos(Nodo *n);
        void copiarNodos(Nodo* este, const Nodo* aCopiar);

        Nodo* raiz;
        int _size;
};

#include "string_map.hpp"

#endif // STRING_MAP_H_
