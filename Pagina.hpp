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
		void addPalavraByIndex (string palavra, int index, int pagina);
		int tamanhoVetor;
		int numero;
		int quantPalavras;
		int quantCaracteres;
	public:
		Palavra *header;
		Palavra *trailer;
		Pagina ();
		int getTamanhoVetor();
		~Pagina ();
		void addPalavra (string palavra, int pagina);
		string imprimePalavras();
		string imprimePalavrasPagina();
		string getPalavra (int index);
		int getNumero(int index);
};

#endif