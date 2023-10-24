#include "Livro.hpp"
#include <fstream>

Livro::Livro(string t){
  
    prox = NULL;
    header = new Pagina();
    trailer = new Pagina();
    titulo = t;
    numPaginas  = 0;
}
Livro::~Livro(){    
    Pagina* p = header;
    for(int i =0; i< numPaginas; i++){
        Pagina *aux = p->prox;
        delete p;
    }
    delete trailer;

}
bool Livro::LeituraLivro(){
    LeitorArquivo l = LeitorArquivo(titulo);
    int caracteres = 0;
    while(1){
        cout<<"grande";
        Pagina *nova = new Pagina();
        string linha;
        while(caracteres < 10){
            cout<< "aqui"<<endl;
            linha = l.proximaPalavra();
            nova->addPalavra(linha);
            caracteres = l.getNumCharac();
            cout<<caracteres<<endl;
            if(linha.empty()){
				break;
			}
        }
        l.zeraNumCharac();
        caracteres = 0;
        addPagina(*nova);
        numPaginas++;
        if(linha.empty()){
        	break;
    	}
    }
    return true;
}
bool Livro::addPagina(Pagina p){
   
    if(numPaginas == 0){
        Pagina *novo = new Pagina(p);//fazer construtor com parametro
        header->prox = novo;
        novo->prox = trailer;
        numPaginas++;
        
    }else{
        Pagina *aux = header;
        Pagina *novo = new Pagina(p);
        for(int i = 0; i < numPaginas; i++){
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = trailer;
        numPaginas++;
    }
    return true;
}
