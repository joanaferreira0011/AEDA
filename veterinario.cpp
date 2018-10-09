
#include "veterinario.h"


string Veterinario::getNome() const {
	return nome;
}

Veterinario::Veterinario(string nome, int cod)
{
	Veterinario::nome = nome;
	codOrdem= cod;
}


