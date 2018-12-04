#include "Aposta.h"
#include <iostream>
#include <sstream>

using namespace std;

bool Aposta::contem(unsigned num) const
{
	return (numeros.find(num) != numeros.end());
}


void Aposta::geraAposta(const vector<unsigned> & valores, unsigned n)
{
	unsigned i = 0;
	for(size_t v = 0; v< valores.size() && i< n; v++)
	{
		if(numeros.find(valores.at(v)) == numeros.end()){
			numeros.insert(valores.at(v));
			i++;
		}
	}
}


unsigned Aposta::calculaCertos(const tabHInt & sorteio) const
{
	unsigned certos = 0;
	unordered_set<unsigned>::const_iterator it = numeros.begin();
	while(it != numeros.end()){
		if(sorteio.find(*it) != numeros.end())
			certos++;
		it++;
	}
	return certos;
}




