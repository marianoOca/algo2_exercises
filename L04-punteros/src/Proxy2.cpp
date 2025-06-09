#include "Proxy2.h"

Proxy::Proxy(ConexionJugador** esto): _conn(esto){};

void Proxy::enviarMensaje(string noSeQueEstoyHaciendo) {
    (*_conn)->enviarMensaje(noSeQueEstoyHaciendo);
}