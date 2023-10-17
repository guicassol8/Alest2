#include "Palavra.hpp"
#ifndef PAGINA_HPP
#define PAGINA_HPP
#define MAXIMOCAR 2500
#include <iostream>
#include <sstream>

using namespace std;

class Pagina {
	private:
		int sortIndex(string palavra);
		void addPalavraByIndex (string palavra, int index);
	public:
		Pagina *prox;
		Palavra *header;
		Palavra *trailer;
		int quantPalavras;
		int quantCaracteres;
		Pagina ();
		void addPalavra (string palavra);
		string imprimePalavras();
};

#endif