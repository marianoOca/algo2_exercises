#include "SistemaDeMensajes.h"



SistemaDeMensajes::SistemaDeMensajes() : _conns(){}

void SistemaDeMensajes::registrarJugador(int id, string ip){
    //if(this->registrado(id)){delete this->_conns[id];}

    this->_conns[id] = new ConexionJugador(ip);
}

void SistemaDeMensajes::desregistrarJugador(int id){
    this->_conns[id] = nullptr;
}

bool SistemaDeMensajes::registrado(int id) const{
    return this->_conns[id] != nullptr;
}

string SistemaDeMensajes::ipJugador(int id) const{
    return (this->_conns[id])->ip();
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    (this->_conns[id])->enviarMensaje(mensaje);
}

#if EJ == 4 || EJ == 5
Proxy* SistemaDeMensajes::obtenerProxy(int id){
    Proxy* comoPuedeFuncionarEsto = new Proxy(this->_conns[id]);
    this->_proxys.push_back(comoPuedeFuncionarEsto);
    return  comoPuedeFuncionarEsto;
}
#elif EJ == 6
Proxy* SistemaDeMensajes::obtenerProxy(int id){
    Proxy* queeee = new Proxy( &(this->_conns[id]));
    this->_proxys.push_back(queeee);
    return  queeee;
}
#endif


SistemaDeMensajes::~SistemaDeMensajes(){
    for(int id=0; id < 4; id++) delete _conns[id];

    #if EJ >3
    for (Proxy* &pr : this->_proxys) delete pr;
    #endif
}