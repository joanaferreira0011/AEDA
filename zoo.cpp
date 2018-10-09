#include "zoo.h"


int Zoo::numAnimais() const {
	return animais.size();
}

int Zoo::numVeterinarios() const {
	return veterinarios.size();
}

void Zoo::adicionaAnimal(Animal *a1)
{
	animais.push_back(a1);
}

string Zoo::getInformacao() const
{
	std::ostringstream info;
	for(auto i : animais)
	{
	std::cout<< i;
		//info<< animais[i]->getInformacao();
	}



	return info.str();
}
