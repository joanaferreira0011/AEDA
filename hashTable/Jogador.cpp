#include "Jogador.h"
#include <iostream>

void Jogador::adicionaAposta(const Aposta & ap)
{

	apostas.insert(ap);


}

unsigned Jogador::apostasNoNumero(unsigned num) const
{
	unsigned count = 0;
	unordered_set<Aposta, apostaHash, apostaHash>::const_iterator it = apostas.begin();
	while(it != apostas.end()){
		if(it->contem(num))
			count++;
		it++;
	}
	return count;
}


tabHAposta Jogador::apostasPremiadas(const tabHInt & sorteio) const
{
	tabHAposta money;
	unordered_set<Aposta, apostaHash, apostaHash>::const_iterator it = apostas.begin();
		while(it != apostas.end()){
			if(it->calculaCertos(sorteio) > 3)
				money.insert(*it);
			it++;
		}
	return money;
}
