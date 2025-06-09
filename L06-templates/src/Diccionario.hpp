#include <cassert>
#include <vector>
#include "Templates.hpp"

template<class Clave, class Valor>
class Diccionario {
    public:
        Diccionario();
        void definir(Clave k, Valor v);
        bool def(Clave k) const;
        Valor obtener(Clave k) const;
        std::vector<Clave> claves() const;

    private:
        struct Asociacion {
            Asociacion(Clave k, Valor v);
            Clave clave;
            Valor valor;

        };
        std::vector<Asociacion> _asociaciones;
        std::vector<Clave> _claves;
};


template<class Clave, class Valor>
Diccionario<Clave, Valor>::Diccionario() : _claves() {}

template<class Clave, class Valor>
Diccionario<Clave, Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {
}

template<class Clave, class Valor>
void Diccionario<Clave, Valor>::definir(Clave k, Valor v) {
	for (unsigned int i = 0; i < _asociaciones.size(); i++) {
		if (_asociaciones[i].clave == k) {
			_asociaciones[i].valor = v;
			return;
		}
	}
	_asociaciones.push_back(Asociacion(k, v));
	if (!contiene(_claves, k)) _claves.push_back(k);
}

template<class Clave, class Valor>
bool Diccionario<Clave, Valor>::def(Clave k) const {
	for (unsigned int i = 0; i < _asociaciones.size(); i++) {
		if (_asociaciones[i].clave == k) {
			return true;
		}
	}
	return false;
}

template<class Clave, class Valor>
Valor Diccionario<Clave, Valor>::obtener(Clave k) const {
	for (unsigned int i = 0; i < _asociaciones.size(); i++) {
		if (_asociaciones[i].clave == k) {
			return _asociaciones[i].valor;
		}
	}
	assert(false);
}

template<class T>
void swapp(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<class Clave, class Valor>
std::vector<Clave> Diccionario<Clave,Valor>::claves() const{
    int size = _claves.size();
    std::vector<Clave> res = _claves;
    for (int i = 0; i < size-1; i++) {
        int imin = i;
        for (int j = i+1; j < size; j++)
            if (res[j] < res[imin]) imin = j;
        swapp(res[i], res[imin]);
    }
    return res;
}