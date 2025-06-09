#include "Diccionario.hpp"

template<class T>
class Multiconjunto {
    public:
        Multiconjunto();
        void agregar(T x);
        int ocurrencias(T x) const;
        bool operator<=(Multiconjunto<T> otro) const;

    private:
        Diccionario<T, int> d_;
};


template<class T>
Multiconjunto<T>::Multiconjunto(){}

template<class T>
void Multiconjunto<T>::agregar(T x){
    if (!d_.def(x)) {
        d_.definir(x, 1);
    } else {
        d_.definir(x, d_.obtener(x) + 1);
    }
}

template<class T>
int Multiconjunto<T>::ocurrencias(T x) const{
    if (!d_.def(x)) return 0;
    return d_.obtener(x);
}

template<class T> // this incluido en otro
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) const{
    std::vector<T> clv = this->d_.claves();
    int size = clv.size();
    for (int i = 0; i < size; i++) {
        if (this->ocurrencias(clv[i]) > otro.ocurrencias(clv[i]))
            return false;
    }
    return true;
}