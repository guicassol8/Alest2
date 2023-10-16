#include <iostream>
#include <cstdlib>
#include "LeitorArquivo.h"
#include "Pagina.hpp"

using namespace std;

int main() {
    LeitorArquivo a = LeitorArquivo("palavras.text");
	Pagina p;

    while(1){
        string b = a.proximaPalavra();
        if(b.empty()){
            break;   
        }
		p.addPalavra(b);
    }
	cout << p.imprimePalavras();
	cout << a.getNumCharac() << endl;
    return 0;
}