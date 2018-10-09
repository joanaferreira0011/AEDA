
#include "animal.h"

string Animal::getNome() const {
	return nome;
}

int Animal::maisJovem =1000000;

Animal::Animal(string nome, int idade)
{
	Animal::nome = nome;
	Animal::idade = idade;
	vet= nullptr;
	if(idade < maisJovem)
		maisJovem=idade;
}



int Animal::getMaisJovem()
{
	return maisJovem;
}


string Cao::getInformacao() const
{
	std::ostringstream info;
	info << "Nome: " << nome << ", idade: " << idade << ", raca: "<< raca;
	return info.str();

}


Cao::Cao(string nome, int idade, string raca): Animal(nome, idade)
{
	Cao::raca = raca;
}

bool Cao::eJovem() const
{
	if(idade<5)
		return true;
	else
		return false;
}

Voador::Voador(int vmax, int amax)
{
	velocidade_max= vmax;
	altura_max= amax;
}

Morcego::Morcego(string nome, int idade, int vmax, int amax): Animal(nome,idade),Voador(vmax,amax){};

bool Morcego::eJovem() const
{
	if(idade<4)
		return true;
	else
		return false;
}


string Morcego::getInformacao() const
{
	std::ostringstream info;
	info << "Nome: " << nome << ", idade: " << idade << ", velocidade maxima: "<< getVelocidade_max() << ", altura maxima: " << getAltura_max() ;
	return info.str();

}
