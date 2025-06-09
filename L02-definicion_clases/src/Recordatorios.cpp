#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7 8, 9 y 10,
class Fecha {
    public:
        Fecha(uint mes, uint dia);
        uint mes();
        uint dia();
        void incrementar_dia();
        bool operator==(Fecha o);

    private:
        int d_;
        int m_;
};

Fecha::Fecha(uint mes, uint dia) : m_(mes), d_(dia){}

uint Fecha::mes(){ return m_; }
uint Fecha::dia(){ return d_; }

void Fecha::incrementar_dia(){
    d_ = d_ + 1;
    if(d_ > dias_en_mes(m_)){
        d_ = 1;
        m_ = m_ + 1;
    }
}

bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return igual_dia&&igual_mes;
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes() ;
    return os;
}

// Ejercicio 11, 12
class Horario {
    public:
        Horario(uint h, uint m);
        uint hora();
        uint min();
        bool operator<(Horario h);

    private:
        int h_;
        int m_;
};

Horario::Horario(uint hora, uint min) : h_(hora), m_(min){}

uint Horario::hora() { return h_; }
uint Horario::min()  { return m_; }

bool Horario::operator<(Horario h) {
    if(this->hora() < h.hora())  return true;
    if(this->hora() == h.hora() &&
       this->min() < h.min()) return true;

    return false;
}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min() ;
    return os;
}


// Ejercicio 13
class Recordatorio {
    public:
        Recordatorio(Fecha f, Horario h, string reco);
        Fecha fecha();
        Horario horario();
        string recordatorio();

    private:
        Fecha f_;
        Horario h_;
        string r_;
};

Recordatorio::Recordatorio(Fecha f, Horario h, string reco) : f_(f), h_(h), r_(reco) {}
/*
Recordatorio::Recordatorio(Fecha( uint mes, uint dia),
                           Horario (uint hora, uint min),
                           string reco) : f_(f), h_(h), r_(reco) {}*/

Fecha Recordatorio::fecha()         { return f_; }
Horario Recordatorio::horario()     { return h_; }
string Recordatorio::recordatorio() { return r_; }

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.recordatorio() << " @ " << r.fecha() << " " << r.horario() ;
    return os;
}

// Ejercicio 14
int findMinPosition(vector<Recordatorio> &s, int d, int h){
    int min = d;

    for(int i = d + 1; i < h; i++) if (s[i].horario() < s[min].horario()) min = i;

    return min;
}

list<Recordatorio> ordenar(vector<Recordatorio> s) {
    if (s.size() == 0) return {};
    for(int i=0; i<s.size()-1; i++) {
        int minPos = findMinPosition(s, i, s.size());
        s[2];
        Recordatorio aux = s[i];
        s[i] = s[minPos];
        s[minPos] = aux;
    }

    list<Recordatorio> l {};
    for(Recordatorio i : s) l.push_back(i);
    return l;
}

class Agenda{
    public:
        Agenda(Fecha fecha_inicial);

        void agregar_recordatorio(Recordatorio rec);
        list<Recordatorio> recordatorios_de_hoy();

        Fecha hoy();
        void incrementar_dia();

    private:
        Fecha hoy_;
        list<Recordatorio> recos_;
};

Agenda::Agenda(Fecha f) : hoy_(f), recos_() {}

void Agenda::agregar_recordatorio(Recordatorio reco){ recos_.push_back(reco); }
void Agenda::incrementar_dia() { return hoy_.incrementar_dia(); }
Fecha Agenda::hoy()            { return hoy_; }

list<Recordatorio> Agenda::recordatorios_de_hoy(){
    vector<Recordatorio> s {};
    for(Recordatorio i : recos_) if (hoy_ == i.fecha()) s.push_back(i);

    return ordenar(s);
}

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy() << endl << "=====" << endl;
    list<Recordatorio> s = a.recordatorios_de_hoy();
    for(Recordatorio i : s) os << i << endl;

    return os;
}