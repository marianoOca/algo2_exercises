#ifndef _COLAPRIOR_H_
#define _COLAPRIOR_H_

#include <vector>

using namespace std;

/* La clase T debe tener definido un operator<
 * que implemente una relación de orden total. */
template<class T>
class ColaPrior {
public:
	ColaPrior();

	// Cantidad de elementos en la cola.
	int tam() const;

	void encolar(const T& elem);        // Encola un elemento.
    // Nota: si se implementa usando un vector, es O(n) en peor caso.

	// Pre: tam() > 0
	const T& proximo() const;           // Devuelve el elemento de mayor prioridad.

	// Pre: tam() > 0
	void desencolar();                  // Saca el elemento de mayor prioridad.
    // Nota: si se implementa usando un vector, es O(n) en peor caso.


	ColaPrior(const vector<T>& elems);  // Constructor que hace heapify.

private:
	void Swap(int i, int j);
    T mayor(int i, int j);

    int hijoIzq(int i);
    int hijoDer(int i);
    int padre(int i);

	vector<T> cont_;
	int tam_;
};

#include "ColaPrior.hpp"

#endif /*_COLAPRIOR_H_*/
