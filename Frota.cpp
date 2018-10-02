#include "Frota.h"
#include <string>

using namespace std;

void Frota::adicionaVeiculo(Veiculo *v1)
{
	veiculos.push_back(v1);
}

int Frota::numVeiculos() const
{
	return veiculos.size();
}

int Frota::menorAno() const
{
	if(veiculos.size()==0)
		return 0;


	int a = (veiculos.at(0))->getAno(); //@a=year of first veiculo

	for(unsigned int i=1; i < veiculos.size(); i++)
	{
		if(veiculos.at(i)->getAno() > a)
			a=veiculos.at(i)->getAno();
	}

	return a;
}

