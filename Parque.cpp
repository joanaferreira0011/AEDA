#include "Parque.h"
#include <vector>
#include <algorithm>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):lotacao(lot), numMaximoClientes(nMaxCli)
{
	vagas = lot;

}

unsigned int ParqueEstacionamento::getNumLugares() const
{
	return lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const
{
	return numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const
{
	/*std::vector<int>::iterator it;
	it = std::find(clientes.begin(), clientes.end(), nome);
	if (it != clientes.end())
	{
		return it;
	}
	else
		return -1;*/

	for (unsigned int i=0; i < clientes.size(); i++)
	{
		if (clientes.at(i).nome == nome)
			{
			return i;
			}
	}

	return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome)
{

	if(numMaximoClientes != clientes.size())
	{
		InfoCartao cliente;
		cliente.nome = nome;
		cliente.presente = false;
		clientes.push_back(cliente);
		return true;
	}
	return false;
}

bool ParqueEstacionamento::entrar(const string & nome)
{
	int i = posicaoCliente(nome);
	if (vagas != 0)
	{
		if(i != -1)
		{
			if (clientes.at(i).presente == false)
				{
				clientes.at(i).presente = true;
				vagas = vagas -1;
				return true;
				}

		}
	}


	return false;

}

bool ParqueEstacionamento::retiraCliente(const string & nome)
{
	unsigned int i = posicaoCliente(nome);

	if (clientes.at(i).presente== false)
	{
		clientes.erase(clientes.begin() + i);
		return true;
	}

	return false;
}

bool ParqueEstacionamento::sair(const string & nome)
{
	int i = posicaoCliente(nome);
			if(i != -1)
			{
				if (clientes.at(i).presente == true)
					{
					clientes.at(i).presente = false;
					vagas = vagas +1;
					return true;
					}

			}



		return false;

}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const
{return lotacao-vagas;}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const
{return clientes.size();}
