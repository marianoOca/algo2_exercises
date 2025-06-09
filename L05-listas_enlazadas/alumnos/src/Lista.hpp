#include "Lista.h"

Lista::Nodo::Nodo(const int& data) : data_(data), sig(nullptr), ant(nullptr){};

Lista::Lista() : prim(nullptr), ulti(nullptr), largo_(0){}

Lista::Lista(const Lista& l) : Lista() { *this = l; }
//Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.

void Lista::borrar(){
    Nodo* temp = prim;
    largo_ = 0;
    while(temp != NULL){
        temp = temp->sig;
        delete(prim);
        prim = temp;
    }
}

Lista::~Lista() { borrar(); }

Lista &Lista::operator=(const Lista& aCopiar) {
    borrar();

    int i = aCopiar.longitud()-1;

    while(i >= 0){
        this->agregarAdelante(aCopiar.iesimo(i));
        i--;
    }

    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo(elem);
    nuevo->sig = prim;
    if(prim != NULL)prim->ant = nuevo;
    prim = nuevo;

    if(ulti == NULL) ulti = nuevo;

    largo_++;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo(elem);
    nuevo->ant = ulti;
    if(ulti != NULL)ulti->sig = nuevo;
    ulti = nuevo;

    if(prim == NULL) prim = nuevo;

    largo_++;
}

void Lista::eliminar(Nat i) {
    largo_--;
    Nodo*F = prim;

    if(largo_ == 0){
        prim = NULL;
        ulti = NULL;
    } else if(i ==  0){
        prim = prim->sig;
        (F->sig)->ant = NULL;
    } else if(i == largo_){
        F = ulti;
        ulti = ulti->ant;
        (F->ant)->sig = NULL;
    } else {
        for(int j = 0; j < i; j++) F = F -> sig;
        (F->ant)->sig = F->sig;
        (F->sig)->ant = F->ant;
    }

    delete F;
}

int Lista::longitud() const { return largo_; }

const int& Lista::iesimo(Nat i) const {
    Nodo*temp=prim;
    while(i>0){temp=temp->sig;i--;}
    const int&queee=temp->data_;
    return queee;
}

int& Lista::iesimo(Nat i) {
    Nodo* temp = prim;

    while(i > 0){
        temp = temp->sig;
        i--;
    }

    return temp->data_;
}

void Lista::mostrar(ostream& o) {
    o << "[";
    if(largo_ > 0) o << iesimo(0);
    for(int i = 1; i < largo_; i++) o << ", " << iesimo(i);
    o << "]";
}