#ifndef PALAVRA_HPP

#define PALAVRA_HPP
#include <iostream>

using namespace std;

class Palavra {
	public:
		Palavra *next;
		Palavra *prev;
		string palavra;
		int pagina;
		int quantPalavras;
		
		Palavra (string palavra = "", Palavra *next = nullptr, Palavra *prev = nullptr);
		~Palavra();
		void setPagina(int pagina);
};

#endif