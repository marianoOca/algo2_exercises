template <typename T>
string_map<T>::Nodo::Nodo() : siguientes(256, nullptr), def(nullptr) { }
template <typename T>
string_map<T>::Nodo::Nodo(T* d) : siguientes(256, nullptr), def(d) { }

template <typename T>
string_map<T>::string_map() : raiz(new Nodo()), _size(0) {};
template <typename T> // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; }

template <typename T>
string_map<T>::~string_map(){ borrarNodos(raiz); }

template <typename T>
void string_map<T>::borrarNodos(string_map<T>::Nodo *n){
    int largo = n->siguientes.size();
    for (int i = 0; i < largo; i++ )
        if(n->siguientes[i] != nullptr) borrarNodos(n->siguientes[i]);

    delete(n->def);
    delete n;
}

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& aCopiar) {
    this->_size = aCopiar._size;
    borrarNodos(raiz);
    this->raiz = new Nodo();
    copiarNodos(this->raiz, aCopiar.raiz);
    return *this;
}

template <typename T>
void string_map<T>::copiarNodos(string_map<T>::Nodo* este, const string_map<T>::Nodo* aCopiar){
    if (aCopiar != nullptr) {
        if (aCopiar->def != nullptr) este->def = new T(*aCopiar->def);

        int largo = aCopiar->siguientes.size();
        for (int i = 0; i < largo; i++) {
            if (aCopiar->siguientes[i] != nullptr) {
                este->siguientes[i] = new Nodo();
                copiarNodos(este->siguientes[i], aCopiar->siguientes[i]);
            }
        }
    }
}
/*
template <typename T>
T& string_map<T>::operator[](const string& clave){
    // considero que si el usuario accede con una nueva key, la va a usar para escribir
    bool escribe = false;
    Nodo* temp = raiz;

    int largo = clave.size();
    for(int i = 0; i < largo; i++){
        int pos = int(clave[i]);
        if (temp->siguientes[pos] == nullptr) {
            temp->siguientes[pos] = new Nodo();
            escribe = true;
        }
        temp = temp->siguientes[pos];
    }

    if (escribe) _size++;
    return *temp->def;
}
*/
template <typename T>
void string_map<T>::insert(const pair<string, T>& clave){
    if (count(clave.first) == 0) _size++;

    Nodo* temp = raiz;

    int largo = clave.first.size();
    for(int i = 0; i < largo; i++){
        int pos = int(clave.first[i]);
        if (temp->siguientes[pos] == nullptr) temp->siguientes[pos] = new Nodo();
        temp = temp->siguientes[pos];
    }

    delete(temp->def);
    temp->def = new T(clave.second);
}

template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo* temp = raiz;

    for(int i = 0; i < clave.size(); i++){
        int pos = int(clave[i]);
        if (temp->siguientes[pos] == nullptr) return 0;
        temp = temp->siguientes[pos];
    }

    if (temp->def != nullptr) return 1;
    return 0;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* temp = raiz;

    for(int i = 0; i < clave.size(); i++) temp = temp->siguientes[int(clave[i])];

    return new T(temp->def);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* temp = raiz;

    for(int i = 0; i < clave.size(); i++) temp = temp->siguientes[int(clave[i])];

    return *temp->def;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* temp = raiz;

    for(int i = 0; i < clave.size(); i++) temp = temp->siguientes[int(clave[i])];

    delete(temp->def);
    temp->def = nullptr;
}

template <typename T>
int string_map<T>::size() const{ return _size; }

template <typename T>
bool string_map<T>::empty() const{ return _size == 0; }