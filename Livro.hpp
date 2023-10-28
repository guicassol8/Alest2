#include "Pagina.hpp"
#include "LeitorArquivo.h"
#include <cstdlib>

class Livro{
    private:
      string titulo;
      string stopWords;
      string *vetStr; 
      Pagina livroPagina;
      Pagina Stopwords;
      Pagina livroSemPagina;
      int numPaginas;
    public:
        Livro();
        ~Livro();
        void  LeituraStopWord(string stopWords);
        void LeituraLivro(string nomeArquivo);
        void pedirLivro ();
        int getNumPaginas();
        void interface();
    
        string ordenaNumero();
        string opcoes();
        void clearConsole();
        void exibeIndiceAlfabetico();
};