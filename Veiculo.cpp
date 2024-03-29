#include "Veiculo.h"
#include <iostream>

using namespace std;

Veiculo::Veiculo(string mc, int m, int a)
{
	marca= mc;
	mes= m;
	ano = a;
}

string Veiculo::getMarca() const
{
	return marca;
}

int Veiculo::getAno() const
{

	return ano;
}

int Veiculo::info() const
{
	cout<< "Marca: " << marca << endl;
	cout<< "Ano: " << ano << endl;
	cout<< "Mes: " << mes << endl;
	return 3;
}

int Motorizado::info() const
{
	int num = Veiculo::info();
	cout<< "Combustivel: " << combustivel << endl;
	cout<< "Cilindrada: " << cilindrada << endl;
	return num + 2;
}

int Automovel::info() const
{
	Motorizado::info();
}


Motorizado::Motorizado(string mc, int m, int a,string c,int cil): Veiculo(mc, m, a)
{
	combustivel = c;
	cilindrada = cil;
}

string Motorizado::getCombustivel() const
{
	return combustivel;
}

Automovel::Automovel(string mc, int m, int a,string c, int cil): Motorizado(mc, m, a, c, cil){}

Camiao::Camiao(string mc, int m, int a,string c, int cil,int cm): Motorizado(mc, m, a, c, cil)
{
	carga_maxima = cm;
}

int Camiao::info() const
{
	return 6;
}

Bicicleta::Bicicleta(string mc, int m, int a,string t): Veiculo(mc, m, a)
{
	tipo=t;
}

int Bicicleta::info() const
{
	return 4;
}
