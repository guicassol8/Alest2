#include "Palavra.hpp"
#ifndef PAGINA_HPP
#define PAGINA_HPP
#define MAXIMOCAR 2500
#include <iostream>
#include <sstream>
#define GREEN "\033[32m"
#define ORANGE "\033[31;33m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define BLUE "\033[34m"

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
		int getOcorrencia(int index);
		int getPagina(int index);
};

string sortColor (string palavra, int aparicoes);

#endif