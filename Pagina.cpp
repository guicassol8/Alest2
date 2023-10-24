#include "Pagina.hpp"

/*
Inicializa a pagina com o header e trailer do LinkedList de palavras
Seta seu next para NULL, visto que pagina eh uma lista simplesmente ligada
*/
Pagina::Pagina (){
		prox = nullptr;
		header = new Palavra("Header");
		trailer = new Palavra("Trailer");
		quantPalavras = 0;
		quantCaracteres = 0;
		tamanhoVetor = 0;
}
Pagina::Pagina(Pagina *p) {
    prox = nullptr;
    header = new Palavra("Header");
    trailer = new Palavra("Trailer");
    quantPalavras = 0;
    quantCaracteres = 0;
    tamanhoVetor = 0;

    
    Palavra *ptr = p->header->next;
    while (ptr != p->trailer) {
        addPalavra(ptr->palavra);
        ptr = ptr->next;
    }
}


//Destrutor da pagina, deleta todas palavras da pagina//
Pagina::~Pagina (){
        Palavra *ptr = header;
        for(int i = 0; i < tamanhoVetor; i++){
		    Palavra *aux = ptr->next;
            delete ptr;
            ptr = aux;
        }
        delete trailer;
}

/*
Funcao que adiciona a palavra na lista de maneira ordenada
@param palavra a ser inserida na pagina
*/
void Pagina::addPalavra (string palavra){
		//Liga a nova palavra ao header e ao trailer se a lista estiver vazia
		if (quantPalavras == 0){
			Palavra *novo = new Palavra(palavra);
			header->next = novo;
			trailer->prev = novo;
			novo->prev = header;
			novo->next = trailer;
			quantPalavras++;
			
		}
		else {
		///Adiciona a palavra na lista de maneira ordenada atraves do indice
			addPalavraByIndex(palavra, sortIndex(palavra));
			quantPalavras++;
		}
		quantCaracteres += palavra.length();
		
}

/*
Retorna o lugar o lugar consequente de onde a palavra deve ser inserida
@param string palavra a ser inserida
@return int index consequente ao de onde a palavra deve ser inserida
*/
int Pagina::sortIndex(string palavra){
		Palavra *ptr = header->next;
		int index = 0;
		//Avanca o ptr ate que uma das flags seja ativada
		while (1){

			//se a palavra do ptr for maior (alfabeticamente) que a palavra a ser inserida, retorna o index, visto que achou seu lugar no ordenamento
			if (ptr->palavra > palavra){
				return index;
			}

			//se o ptr->next for o trailer, retorna o index + 1, visto que o elemento chegou ao final da lista
			//o retorno de index + 1 se da pelo fato de que a lista tera de crescer, e seu novo indice deve ser o tamanho da lista (index final + 1)
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


/*
Funcao que adiciona a palavra na lista de maneira ordenada a partir do index consequente ao qual ela deve ser adicionada
@param string palavra a ser inserida
@param int index consequente ao de onde a palavra deve ser inserida
*/
void Pagina::addPalavraByIndex (string palavra, int index){
	//Flag para se o indice for maior que a quantidade de palavras ou menor que o index, representando um erro
	if (index > quantPalavras|| index < 0){
		throw out_of_range("Index out of range");
	}

	Palavra *ptr = header->next;

	//Leva o ptr ate a posicao do index
	for (int i = 0; i < index; i++){
		ptr = ptr->next;
	}

	if (ptr->prev->palavra == palavra){
		ptr->prev->quantPalavras++;
		return;
	}

	/*
	Faz com que o ptr "pule" uma cara para frente, de maneira que o novo vai ser adicionado antes do ptr (no index desejado)\n
	Fazendo todos os devidos ajutstes de ponteiros next e prev
	*/
	Palavra *novo = new Palavra(palavra);
	ptr->prev->next = novo;
	novo->prev = ptr->prev;
	novo->next = ptr;
	ptr->prev = novo;
	tamanhoVetor++;
	#ifdef DEBUG
	cerr << "palavra: " << ptr->palavra << endl;
	#endif
}

/*
Funcao que transforma todas palavras em uma string organizada
@return string com todas palavras
*/
string Pagina::imprimePalavras(){
	Palavra *ptr = header->next;
	stringstream ss;
	while (ptr != trailer){
		ss << "|";
		ss << ptr->palavra << "|";
		ss << " Quantidade de Aparicoes: ";
		ss << ptr->quantPalavras << endl;
		ptr = ptr->next;
	}
	ss << endl;
	ss << "Numero de caracteres: " << quantCaracteres << endl;
	return ss.str();
}