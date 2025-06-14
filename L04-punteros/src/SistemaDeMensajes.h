#ifndef SISTEMADEMENSAJES_H
#define SISTEMADEMENSAJES_H

#include "ConexionJugador.h"
#include <string>
#include <vector>

#if EJ == 4 || EJ == 5
#include "Proxy.h"
#elif EJ == 6
#include "Proxy2.h"
#endif

using namespace std;

class SistemaDeMensajes {
  public:
    SistemaDeMensajes();
    void registrarJugador(int id, string ip);   // Pre: 0 <= id < 4
    void desregistrarJugador(int id);           // Pre: 0 <= id < 4
    bool registrado(int id) const;              // Pre: 0 <= id < 4
    void enviarMensaje(int id, string mensaje); // Pre: registrado(id)
    string ipJugador(int id) const;             // Pre: registrado(id)

    #if EJ >3
    Proxy* obtenerProxy(int id);                // Pre: registrado(id)
    #endif

    ~SistemaDeMensajes();

  private:
    ConexionJugador* _conns[4];

    #if EJ >3
    vector<Proxy*> _proxys;
    #endif
};

#endif
