#include "parque.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include <vector>
#include <algorithm>
using namespace std;

bool InfoCartao:: operator == (const InfoCartao &ic1) const
{
	if (this->nome == ic1.nome)
		return true;
	else
		return false;
}

bool InfoCartao:: operator < (const InfoCartao &ic1) const{
	if(this->frequencia == ic1.frequencia)
	{
		if (this->nome < ic1.nome)
				return true;
			else
				return false;
	}

	//else
	if (this->frequencia > ic1.frequencia)
		return true;
	else
		return false;
}

bool compNome (const InfoCartao &ic1, const InfoCartao &ic2) {

	return ic1.nome < ic2.nome;

}

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):
	lotacao(lot), numMaximoClientes(nMaxCli) {
    numClientes = 0;
    vagas=lot; 
}

ParqueEstacionamento::~ParqueEstacionamento() {}

vector<InfoCartao> ParqueEstacionamento::getClientes() const { return clientes; }


bool ParqueEstacionamento::adicionaCliente(const string & nome)
{
 	if ( numClientes == numMaximoClientes ) return false;
	if ( posicaoCliente(nome) != -1 ) return false;
	InfoCartao info;
	info.nome = nome;
    info.presente = false;
    info.frequencia = 0;  // a fazer
	clientes.push_back(info);
	numClientes++;
	return true;
}
 
bool ParqueEstacionamento::retiraCliente(const string & nome)
{
	for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++)
		if ( it->nome == nome ) {
			if ( it->presente == false ) {
				clientes.erase(it);
				numClientes--;
				return true;
			}
			else return false;
		}
	return false;
}
  
unsigned int ParqueEstacionamento::getNumLugares() const
{
	return lotacao;
}
                   
unsigned int ParqueEstacionamento::getNumLugaresOcupados() const
{
	return lotacao-vagas;
}

bool ParqueEstacionamento::entrar(const string & nome)
{
	if ( vagas == 0 ) return false;
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == true ) return false;
	clientes[pos].presente = true;
	clientes[pos].frequencia++;
	vagas--;
	return true;
}

bool ParqueEstacionamento::sair(const string & nome)
{
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == false ) return false;
	clientes[pos].presente = false;
	vagas++;
	return true;
}

// a alterar
int ParqueEstacionamento::posicaoCliente(const string & nome) const {
	InfoCartao *cartao =new InfoCartao;
	cartao->nome=nome;
	return sequentialSearch(clientes, *cartao);

}

int ParqueEstacionamento::getFrequencia(const string &nome) const
{
	int pos = posicaoCliente(nome);
	if(pos == -1)
		throw ClienteNaoExistente(nome);
	else
		return clientes[pos].frequencia;
}

void ParqueEstacionamento::ordenaClientesPorFrequencia()
{
	insertionSort(clientes);
}

vector<string> ParqueEstacionamento::clientesGamaUso(int n1, int n2){
	vector<InfoCartao> clientesCondicao;
	vector<string> clientesCondicaoRetorno;
	for(auto &cliente: clientes)
	{
		if(cliente.frequencia>= n1 && cliente.frequencia <= n2)
			clientesCondicao.push_back(cliente);
	}


	insertionSort(clientesCondicao);

	for(auto &a:clientesCondicao)
	{
		clientesCondicaoRetorno.push_back(a.nome);
	}

	return clientesCondicaoRetorno;
}

void ParqueEstacionamento::ordenaClientesPorNome()
{
	sort (clientes.begin(), clientes.end(), compNome);
}
