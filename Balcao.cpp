#include <queue>
#include <cstdlib>
#include "Balcao.h"

using namespace std;


Cliente::Cliente() {
	numPresentes = rand()%5+1;
}


int Cliente::getNumPresentes() const {
	return numPresentes;
}


Balcao::Balcao(int te): tempo_embrulho(te) {
	tempo_atual=0;
	prox_chegada = rand()%20+1;
	prox_saida = 0;
	clientes_atendidos = 0;
}      


void Balcao:: proximoEvento()
{
	// a alterar
}


void Balcao::chegada()
{

	Cliente *cliente = new Cliente();
	if(clientes.empty())
			prox_saida = tempo_atual + cliente->getNumPresentes()*tempo_embrulho;
	clientes.push(*cliente);
	prox_chegada = rand()%20+1;

	cout<< "tempo= "<< tempo_atual <<" chegou novo cliente com " << cliente->getNumPresentes() <<" presentes\n";
}   


void Balcao::saida()
{
	try{
		if(clientes.empty())
			throw FilaVazia();
		clientes.pop();
		prox_saida= tempo_atual + clientes.front().getNumPresentes()*tempo_embrulho;
	}
	catch(...){}

}


int Balcao::getTempoAtual() const { return tempo_atual; }


int Balcao::getProxChegada() const { return prox_chegada; }


ostream & operator << (ostream & out, const Balcao & b1)
{
	// a alterar
     return out;
}


int Balcao::getTempoEmbrulho() const {
	return tempo_embrulho;
}


int Balcao::getProxSaida() const {
	return prox_saida;
}


int Balcao::getClientesAtendidos() const {
	return clientes_atendidos;
}


Cliente & Balcao::getProxCliente() {
	if(clientes.empty())
		throw FilaVazia();
	else
	return clientes.front();
}

      
