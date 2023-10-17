#include "Palavra.hpp"

/**
 * @brief Construtor que recebe uma string palavra e cria um objeto Palavra.
 * 
 * @exception Ha a possibilidade do objeto ja ser criado recebendo seu next e ou seu prev
 * 
 * @param string palavra
 * @param Palavra *next
 * @param Palavra *prev
*/

Palavra::Palavra(string palavra, Palavra *next, Palavra *prev){
		this->palavra = palavra;
		this->next = next;
		this->prev = prev;
		quantPalavras = 1;
}