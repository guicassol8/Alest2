#include "Livro.hpp"
#include <fstream>
#include <sstream>
#include <string>
#define Tstp 248
//construtor.
Livro::Livro(){

    numPaginas  = 0;
}
//destrutor.
Livro::~Livro() {

}
void  Livro:: LeituraStopWord(string stopWords){
    LeitorArquivo S = LeitorArquivo(stopWords);
    string *vetStp = new string[Tstp];
    string stop;
    for(int i = 0; i< Tstp; i++){
          stop = S.proximaPalavra();
           vetStp[i] = stop;
    }
   
    vetStr = vetStp;
    
}


//le as palavras, verifica se sao stop words e cria paginas acom essas palavras.
void Livro::LeituraLivro(string titulo){
    LeitorArquivo l = LeitorArquivo(titulo);
    int caracteres = 0;
    int paginas = 1;
    int semPagina =1;
    while(1){
        string linha;
        while(caracteres < 10){
            int passa = 1;
            linha = l.proximaPalavra();
            //transforma em minuscula
            for (char &caractere : linha) {
                caractere = tolower(caractere);
            }
            //stop words    
            for(int i = 0; i < Tstp; i++){
                if(linha == vetStr[i]){
                    Stopwords.addPalavra(linha, paginas);
                    passa = 0;
                    break;
                }
            }
             if(linha.empty()){
				break;
			}
            //adiciona palavra 
            if(passa == 1){
                livroPagina.addPalavra(linha, paginas);
                livroSemPagina.addPalavra(linha, semPagina);
            }   
            caracteres = l.getNumCharac();
            
        }
        l.zeraNumCharac();
        caracteres = 0;        
        if(linha.empty()){
        	break;
    	}
        paginas++;
    }
   
}

//getter para numero d epaginas total.
int Livro:: getNumPaginas(){
    return numPaginas;
}



void Livro::pedirLivro(){
    clearConsole();
    cout << "Digite o nome do arquivo: " << endl;
    while (1){
        cin >> titulo;
        ifstream arq(titulo);
        if (!arq.is_open()) {
            clearConsole();
            cout << "Digite um arquivo valido: " << endl;
            continue;
        }
        arq.close();
        break;
    }
    clearConsole();
    cout << "Digite o nome do arquivo de stop words: " << endl;
    while (1){
        cin >> stopWords;
        ifstream arq(stopWords);
        if (!arq.is_open()) {
            clearConsole();
            cout << "Digite um arquivo valido: " << endl;
            continue;
        }
        arq.close();
        break;
    }
}

void Livro::interface(){
   pedirLivro();
   int escolha = 0;
   bool validacao = false;
   string lixo;
   while (escolha != 7){
        clearConsole();
        if (validacao){
            cout << "Opcao invalida!" << endl;
            validacao = !validacao;
        }
        cout << opcoes() << endl;
        cin >> escolha;
        switch (escolha){
            case 1:
                exibeIndiceAlfabetico();
                cout << "Digite algo para voltar a interface" << endl;
                getline (cin,lixo);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                validacao = true;
                break;
        }
   }
}

string Livro::ordenaNumero(){
    struct vetor{
        string palavra;
        int num;
    };
        int tam =livroSemPagina.getTamanhoVetor();
        vetor *vet = new vetor[tam];
        for(int i = 0; i < tam; i++){
            vet[i].palavra = livroSemPagina.getPalavra(i);
            vet[i].num = livroSemPagina.getNumero(i);
        }
        //Bubble Sort
        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                if(vet[i].num > vet[j].num){
                    string aux = vet[i].palavra;
                    vet[i].palavra = vet[j].palavra;
                    vet[j].palavra = aux;
                    int aux2 = vet[i].num;
                    vet[i].num = vet[j].num;
                    vet[j].num = aux2;
                }
            }
        }
       
        stringstream ss;
        ss << "Indice Remissivo  por ordem decrescente: " << endl;
        ss<<"------------------------------------------------"<<endl;
        for(int i = 0; i < tam; i++){  
            ss << "| ";
            ss<< vet[i].palavra << " |";
            ss << " Quantidade de Aparicoes: ";
            ss << vet[i].num << endl;
        }
        ss<<"------------------------------------------------"<<endl;
        return ss.str();
}

string Livro::opcoes(){
    stringstream ss;
    ss << " 1 - Exibir todo o indice remissivo (em ordem alfabetica)" << endl << endl;
    ss << " 2 - Exibir todo o indice remissivo (em ordem decrescente do numero de ocorrencias no texto)" << endl << endl;
    ss << " 3 - Exibir o informacoes sobre a catalogacao" << endl << endl;
    ss << " 4 - Exibir a palavra com o maior numero de ocorrencia" << endl << endl;
    ss << " 5 - Pesquisar palavra" << endl << endl;
    ss << " 6 - Pesquisar palavra e pagina (digite palavra depois pagina)" << endl << endl;
    ss << " 7 - Encerrar Programa";
    return ss.str();
}

void Livro::exibeIndiceAlfabetico(){
    cout << "Indice Remissivo" << endl;
    cout << livroSemPagina.imprimePalavras();
}

void Livro::clearConsole(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}