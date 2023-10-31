#include <iostream>
#include <cstdlib>
#include "LeitorArquivo.h"
#include "Pagina.hpp"
#include "Livro.hpp"

using namespace std;

int main() {
    Livro l1 ;
    string A = "Tentativa.txt";
    string S = "stopwords-en.txt";
    // l1.LeituraStopWord(S);
    // l1.LeituraLivro(A);
    // l1.exibeIndiceAlfabetico();
    // l1.exibeIndiceNumerico();
    // l1.clearConsole();
    // cout << l1.opcoes();
    l1.interface();
    return 0;
}