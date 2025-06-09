
template <class T>
Conjunto<T>::Nodo::Nodo(const T& v) : valor(v), izq(nullptr), der(nullptr){};

template <class T>
Conjunto<T>::Conjunto() : h_(0), _raiz(nullptr){}

template <class T>
Conjunto<T>::~Conjunto() { destruir(_raiz); }

template <class T>
void Conjunto<T>::destruir(Conjunto<T>::Nodo * n) {
    if (n != NULL) {
        destruir(n->izq);
        destruir(n->der);
        delete n;
    }
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const { return esta(_raiz, clave); }

template <class T>
bool Conjunto<T>::esta(Conjunto<T>::Nodo * n, const T& clave) const{
    if (n == nullptr) return false;
    if (n->valor == clave) return true;
    return esta(n->izq, clave)||esta(n->der, clave);
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if (!pertenece(clave)){
        h_ = h_ + 1;
        if(_raiz == nullptr) {
            _raiz = new Nodo(clave);
        } else {
            Nodo *temp = _raiz;
            bool listo = false;
            while (!listo) {
                if (temp->valor < clave) {
                    if (temp->der == nullptr) {
                        temp->der = new Nodo(clave);
                        listo = true;
                    } else {
                        temp = temp->der;
                    }
                } else { //temp->valor > clave
                    if (temp->izq == nullptr) {
                        temp->izq = new Nodo(clave);
                        listo = true;
                    } else {
                        temp = temp->izq;
                    }
                }
            }
            //destruir(temp);
        }
    }
}

template <class T>
void Conjunto<T>::remover(const T& elem) {
    if (pertenece(elem)) {
        h_ = h_ - 1;

        T aBorrar = elem;
        Nodo *temp = _raiz;

        if (_raiz->valor == elem) {
            if (_raiz->der == nullptr && _raiz->izq == nullptr) {
                delete _raiz;
                _raiz = nullptr;
                return;
            } else if (_raiz->der != nullptr && _raiz->izq == nullptr) {
                _raiz = _raiz->der;
                delete temp;
                return;
            } else if (_raiz->der == nullptr && _raiz->izq != nullptr) {
                _raiz = _raiz->izq;
                delete temp;
                return;
            } else { // _raiz->der != nullptr && _raiz->izq != nullptr
                _raiz->valor = minNodo(_raiz->der);
                aBorrar = _raiz->valor;
                temp = _raiz->der;
            }
        }

        while (esta(temp, aBorrar)) {
            if (temp->valor == aBorrar){
                volarNodo(temp, _raiz);
                return;
            } else if (temp->der != nullptr && temp->der->valor == aBorrar) {
                volarNodo(temp->der, temp);
                return;
            } else if (temp->izq != nullptr && temp->izq->valor == aBorrar) {
                volarNodo(temp->izq, temp);
                return;
            } else if (temp->valor < aBorrar) {
                temp = temp->der;
            } else { // temp->valor > aBorrar
                temp = temp->izq;
            }
        }
    }
}

template <class T>
void Conjunto<T>::volarNodo(Conjunto<T>::Nodo * F, Conjunto<T>::Nodo * malPadre) { // F por respeto
    string dir = "der";                   // asumo F == malPadre->der
    if (F == malPadre->izq) dir = "izq";  // si no, lo cambio

    if (F->der == nullptr && F->izq == nullptr) {
        if (dir == "der") malPadre->der = nullptr;
        if (dir == "izq") malPadre->izq = nullptr;
        delete F;
        return;
    } else if (F->der != nullptr && F->izq == nullptr) {
        if (dir == "der") malPadre->der = F->der;
        if (dir == "izq") malPadre->izq = F->der;
        delete F;
        return;
    } else if (F->der == nullptr && F->izq != nullptr) {
        if (dir == "der") malPadre->der = F->izq;
        if (dir == "izq") malPadre->izq = F->izq;
        delete F;
        return;
    } else { // _raiz->der != nullptr && _raiz->izq != nullptr
        F->valor = minNodo(F->der);
        T aBorrar = F->valor;
        Nodo *temp = F->der;

        while (esta(temp, aBorrar)) {
            if (temp->valor == aBorrar){
                volarNodo(temp, F);
                return;
            } else if (temp->der != nullptr && temp->der->valor == aBorrar) {
                volarNodo(temp->der, temp);
                return;
            } else if (temp->izq != nullptr && temp->izq->valor == aBorrar) {
                volarNodo(temp->izq, temp);
                return;
            } else if (temp->valor < aBorrar) {
                temp = temp->der;
            } else { // temp->valor > aBorrar
                temp = temp->izq;
            }
        }
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) { // asumo que clave pertenece a conj
    Nodo *temp = _raiz;

    while(true) {
        if (temp->izq != nullptr && temp->izq->valor == clave
            && temp->izq->der == nullptr) return temp->valor;
        if (temp->izq != nullptr && temp->izq->der != nullptr
            && temp->izq->der->valor == clave) return minNodo(temp);
        if (temp->valor == clave && temp->der != nullptr) return minNodo(temp->der);

        if (temp->valor > clave) {
            temp = temp->izq;
        } else {
            temp = temp->der;
        }
        //evita que el programa se cuelgue si algo sale mal
        if(temp->izq == nullptr && temp->der == nullptr) return temp->valor;
    }
}

template <class T>
const T& Conjunto<T>::minimo() const { return minNodo(_raiz); } // asumo que Conj != vacío

template <class T>
const T& Conjunto<T>::minNodo(Conjunto<T>::Nodo * n) const {
    while (n->izq != nullptr) n = n->izq;
    return n->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const { // asumo que Conj != vacío
    Nodo *temp = _raiz;
    while (temp->der != nullptr) temp = temp->der;
    return temp->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const { return h_; }

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    //assert(false);
}

