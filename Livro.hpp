#include "Pagina.hpp"
#include "LeitorArquivo.h"

class Livro{
    private:
      string titulo;
      
       
    public:
        Pagina *header;
        Pagina *trailer;
        Pagina *prox;
        int numPaginas;
        Livro(string t);
        ~Livro();
        bool LeituraLivro();
        bool addPagina(Pagina pagina);
    

};