#include <iostream>

using namespace std;

class Livro{
	private:
		string nome;
		Pagina *head;
		Pagina *tail;
		int quantPaginas;
		Livro (string nome){
			this->nome = nome;
			this->quantPaginas = 0;
			this->head = NULL;
			this->tail = NULL;
		}
};

class Pagina {
	public:
		Pagina *next;
		Palavra *header;
		Palavra *trailer;
		int quantPalavras;
		Pagina (){
			Pagina *next = NULL;
			Palavra *header = new Palavra("Header");
			Palavra *trailer = new Palavra("Trailer");
			quantPalavras = 0;
		}
		void addPalavra (string palavra){
			if (quantPalavras == 0){
				Palavra *novo = new Palavra(palavra);
				header->next = novo;
				trailer->prev = novo;
				novo->prev = header;
				novo->next = trailer;
				quantPalavras++;
			}
			else {
				addPalavraByIndex(palavra, sortIndex(palavra));
			}
		}
		int sortIndex(string palavra){
			Palavra *ptr = header;
			int index = 0;
			while (1){
				if (ptr->next->palavra >= palavra){
					return index;
				}
				if (ptr->next == trailer){
					return index + 1;
				}
				index++;
				ptr = ptr->next;
			}
			#ifdef DEBUG
			cerr << "deu errado" << endl;
			#endif
			return -1;
		}
		void addPalavraByIndex (string palavra, int index){
			
			if (index >= quantPalavras|| index < 0){
				throw out_of_range("Index out of range");
			}

			Palavra *ptr = header->next;

			for (int i = 0; i < index; i++){
				ptr = ptr->next;
			}
			Palavra *novo = new Palavra(palavra);
			ptr->prev->next = novo;
			novo->prev = ptr->prev;
			novo->next = ptr;
			ptr->prev = novo;
			#ifdef DEBUG
			cerr << "palavra: " ptr->palavra << endl;
			#endif
		}
};

class Palavra {
	public:
		Palavra *next;
		Palavra *prev;
		string palavra;
		Palavra (string palavra){
			this->palavra = palavra;
			this->next = NULL;
			this->prev = NULL;
		}
};