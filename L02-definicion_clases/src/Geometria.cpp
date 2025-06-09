#include <iostream>

using namespace std;

using uint = unsigned int;


// Ejercicio 1
class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto , uint ancho ) : alto_(alto), ancho_(ancho) {}

uint Rectangulo::alto()  { return alto_; }
uint Rectangulo::ancho() { return this->ancho_; }
float Rectangulo::area() { return (this->ancho_)*alto_; }


// Ejercicio 2
#define PI 3.14

class Elipse {
    public:
        Elipse(uint a, uint b);
        uint r_a();
        uint r_b();
        float area();

    private:
        int a_;
        int b_;
};

Elipse::Elipse(uint a , uint b ) : a_(a), b_(b) {}

uint Elipse::r_a()   { return a_; }
uint Elipse::r_b()   { return b_; }
float Elipse::area() { return a_*b_*PI; }


// Ejercicio 3
class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado()  { return r_.alto(); }
float Cuadrado::area() { return r_.area(); }


// Ejercicio 4
class Circulo {
    public:
        Circulo(uint r);
        uint radio();
        float area();

    private:
        Elipse r_;
};

Circulo::Circulo(uint r): r_(r, r) {}

uint Circulo::radio() { return r_.r_a(); }
float Circulo::area() { return r_.area(); }


// Ejercicio 5
ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

ostream& operator<<(ostream& os, Elipse e) {
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}


// Ejercicio 6
ostream& operator<<(ostream& os, Cuadrado c) {
    os << "Cuad(" << c.lado()  << ")";
    return os;
}

ostream& operator<<(ostream& os, Circulo c) {
    os << "Circ(" << c.radio() << ")";
    return os;
}