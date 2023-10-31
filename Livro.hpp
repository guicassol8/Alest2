#include "Pagina.hpp"
#include "LeitorArquivo.h"
#include <cstdlib>
#include <iomanip>

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
        double percentual();
        string ordenaNumero();
        string opcoes();
        void clearConsole();
        void exibeIndiceAlfabetico();
        void exibeIndiceNumerico();
        string maiorAparicao ();
        void exibeMaiorParicao ();
        int palavrasDiferentes();
        int totalPalavras();
        int totalStopWords();
        int pesquisaTotal(string palavra , int pagina);
        void exibirInfoCatalogacao();
        string pesquisaPalavra(string palavra);
        void exibepesquisaPalavra(string palavra);
        void exibepesquisaTotal(string palavra , int pagina);
};