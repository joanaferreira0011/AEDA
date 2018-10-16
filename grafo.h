#include <iostream>
#include <vector>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */



template <class N, class A> class Aresta;

template <class N, class A>
class No {
public:
	N info;
	vector< Aresta<N,A> > arestas;
	No(N inf) {
		info = inf;
	}
};

template <class N, class A>
class Aresta {
public:
	A valor;
	No<N,A> *destino;
	Aresta(No<N,A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};

template <class N, class A> 
class Grafo { 
	vector< No<N,A> *> nos;
  public: 
    Grafo();
    ~Grafo(); 
    Grafo & inserirNo(const N &dados);
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val);
    Grafo & eliminarAresta(const N &inicio, const N &fim);
    A & valorAresta(const N &inicio, const N &fim);
    int numArestas(void) const;
    int numNos(void) const;
    void imprimir(std::ostream &os) const; 
};

template <class N, class A> 
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);


// excecao  NoRepetido
template <class N>
class NoRepetido
{
public:
   N info;
   NoRepetido(N inf) { info=inf; }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{ out << "No repetido: " << no.info; return out; }



// excecao NoInexistente
template <class N>
class NoInexistente {
public:
	N info;
	NoInexistente(N inf) {
		info = inf;
	}
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }

template <class N, class A>
Grafo<N,A>::Grafo()
{
}

template <class N, class A>
Grafo<N,A>::~Grafo()
{
	for(auto& i : nos)
		{
			delete[] i;
		}

	nos.clear();
}

template <class N, class A>
int Grafo<N,A>::numNos() const
{
	return nos.size();
}

template <class N, class A>
int Grafo<N,A>::numArestas() const
{
	int numArestas = 0;

	for(auto& i : nos)
	{
		numArestas += (*i).arestas.size();
	}

	return numArestas;
}

template <class N, class A>
Grafo<N,A> & Grafo<N,A>::inserirNo(const N &dados)
{
	bool equal = false;

	for(auto& i: nos)
	{
		if ((*i).info == dados)
			equal = true;
	}

	if (equal == true)
		throw NoRepetido<N>(dados);
	else
		{
		No<N, A> *No1 =new No<N, A>(dados);
		nos.push_back(No1);
		}

	return *this;

}
