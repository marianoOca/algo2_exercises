
template<class T>
ColaPrior<T>::ColaPrior() : cont_(), tam_(0) {}

template<class T>
void ColaPrior<T>::Swap(int i, int j){
    T temp = cont_[i];
    cont_[i] = cont_[j];
    cont_[j] = temp;
}

template<class T>   // Pre: i < tam_ && j < tam_
T ColaPrior<T>::mayor(int i, int j){
    if (cont_[i] > cont_[j]) return i;
    return j;   // cont_[i] < cont_[j]
}

template<class T>
int ColaPrior<T>::hijoIzq(int i){ return 2*i + 1; }

template<class T>
int ColaPrior<T>::hijoDer(int i){ return 2*i + 2; }

template<class T>
int ColaPrior<T>::padre(int i){ return (i - 1) / 2; }

template<class T>
int ColaPrior<T>::tam() const { return tam_; }

template<class T>
void ColaPrior<T>::encolar(const T& elem) {
    int i = tam_;

    cont_.push_back(elem);

    while ( i != 0 && cont_[padre(i)] < cont_[i]) {
        Swap(i, padre(i));
        i = padre(i);
    }

    tam_++;
}

template<class T>
const T& ColaPrior<T>::proximo() const { if(tam_ > 0) return cont_[0]; }

template<class T>
void ColaPrior<T>::desencolar() {
    tam_--;

    Swap(0, tam_);
    cont_.pop_back();

    int i = 0;
    while ( (tam_ > hijoIzq(i) && cont_[i] < cont_[hijoIzq(i)]) ||
            (tam_ > hijoDer(i) && cont_[i] < cont_[hijoDer(i)]) ) {
        if (tam_ > hijoDer(i)) {        // si está el nodo derecho también está el izquierdo
            int m = mayor(hijoIzq(i), hijoDer(i));
            Swap(i, m);
            i = m;
        } else {                        // sólo está el izquierdo
            Swap(i, hijoIzq(i));
            i = hijoDer(i);
        }
    }
}

template<class T>
ColaPrior<T>::ColaPrior(const vector<T>& elems) {
    cont_ = {};
    tam_ = 0;

    for (int i = 0 ; i < elems.size() ; i ++ ) {
        encolar(elems[i]);
	}
}

