#include <iostream>
#include <cstdlib>
#include "LeitorArquivo.h"
#include "Pagina.hpp"
#include "Livro.hpp"

using namespace std;

int main() {
    // Livro l1("palavras.text");
    // l1.LeituraLivro();
    // cout<< l1.str()<<endl;
    // LeitorArquivo a = LeitorArquivo("Tentativa.txt");
    Livro l1 ;
    string A = "Tentativa.txt";
    string S = "stopwords-en.txt";
    l1.LeituraStopWord(S);
    l1.LeituraLivro(A);
    cout<< l1.ordenaNumero();
    l1.exibeIndiceAlfabetico();
    // Pagina pagina;
    // int paginas = 0;
    // bool aux = true;
    // while(1){
    //     string b = a.proximaPalavra(); 
    //     if(b.empty()){
    //         break;   
    //     }
    //     pagina.addPalavra(b,paginas);
    //     if (aux){
    //         paginas++;
    //         aux = false;
    //     }
    //     else{
    //         aux = true;
    //     }
    // }
    // cout << pagina.imprimePalavras();
    return 0;
}