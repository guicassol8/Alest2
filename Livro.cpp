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
void  Livro:: LeituraStopWord(string stopWord){
    LeitorArquivo S = LeitorArquivo(stopWord);
    string *vetStp = new string[Tstp];
    string stop;
    for(int i = 0; i< Tstp; i++){
          stop = S.proximaPalavra();
           vetStp[i] = stop;
    }
   
    vetStr = vetStp;
    
}


//le as palavras, verifica se sao stop words e cria paginas acom essas palavras.
void Livro::LeituraLivro(string nomeArquivo){
    LeitorArquivo l = LeitorArquivo(nomeArquivo);
    int caracteres = 0;
    int paginas = 1;
    int semPagina = 1;
    while(1){
        string linha;
        while(caracteres < 2500){
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
    cout << "Digite o nome do arquivo de stopwords: " << endl;
    string aux;
    while (1){
        cin >> aux;
        ifstream arq(aux);
        if (!arq.is_open()) {
            clearConsole();
            cout << "Digite um arquivo valido: " << endl;
            continue;
        }
        arq.close();
        break;
    }
    cout << "Stopwords: " << aux << endl;
    LeituraStopWord(aux);
    clearConsole();
    cout << "Digite o nome do arquivo do livro: " << endl;
    while (1){
        cin >> aux;
        ifstream arq(aux);
        if (!arq.is_open()) {
            clearConsole();
            cout << "Digite um arquivo valido: " << endl;
            continue;
        }
        arq.close();
        break;
    }
    cout << "Livro: " << aux << endl;
    LeituraLivro(aux);
}

void Livro::interface(){
   pedirLivro();
   int escolha = 0;
   bool validacao = false;
   string lixo;
   string palavra;
   int pagina;
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
                clearConsole();
                exibeIndiceAlfabetico();
                cout << "Digite algo para voltar a interface" << endl;
                cin >> lixo;
                break;
            case 2:
                clearConsole();
                exibeIndiceNumerico();
                cout << "Digite algo para voltar a interface" << endl;
                cin >> lixo;
                break;
            case 3:
                clearConsole();
                exibirInfoCatalogacao();
                cout << "Digite algo para voltar a interface" << endl;
                cin >> lixo;
                break;
            case 4:
                clearConsole();
                exibeMaiorParicao();
                cout << "Digite algo para voltar a interface" << endl;
                cin >> lixo;
                break;
            case 5:
                clearConsole();
                cout<<"Digite uma palavra"<<endl;
                cin>>palavra;
                clearConsole();
                exibepesquisaPalavra(palavra);
                cout << "Digite algo para voltar a interface" << endl;
                cin>>lixo;
                break;
            case 6:
                clearConsole();
                cout<<"Digite uma palavra"<<endl;
                cin>>palavra;
                cout<<"Digite uma pagina" <<endl;
                cin>>pagina;
                clearConsole();
                exibepesquisaTotal( palavra, pagina);
                cout << "Digite algo para voltar a interface" << endl;
                cin >> lixo;
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
            vet[i].num = livroSemPagina.getOcorrencia(i);
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
        
        for (int i = 0; i < tam; i++) {
            for (int j = i + 1; j < tam; j++) {
                if ((vet[i].num == vet[j].num && vet[i].palavra > vet[j].palavra)) {
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
            ss<< sortColor(vet[i].palavra,vet[i].num) << " |";
            ss << endl << "| Ocorrencias: ";
            ss << vet[i].num;
            ss << " |" << endl;
        }
        ss<<"------------------------------------------------"<<endl;
        return ss.str();
}

string Livro::opcoes(){
    stringstream ss;
    ss << "-----------------------------------------------------------------------------------------------" << endl;
    ss << BLUE << "(1)" << RESET << " - Exibir todo o indice remissivo (em ordem alfabetica)" << endl << endl;
    ss << BLUE << "(2)" << RESET << " - Exibir todo o indice remissivo (em ordem decrescente do numero de ocorrencias no texto)" << endl << endl;
    ss << BLUE << "(3)" << RESET << " - Exibir o informacoes sobre a catalogacao" << endl << endl;
    ss << BLUE << "(4)" << RESET << " - Exibir a palavra com o maior numero de ocorrencia" << endl << endl;
    ss << BLUE << "(5)" << RESET << " - Pesquisar palavra" << endl << endl;
    ss << BLUE << "(6)" << RESET << " - Pesquisar palavra e pagina (digite palavra depois pagina)" << endl << endl;
    ss << BLUE << "(7)" << RESET << " - Encerrar Programa" << endl;
    ss << "-----------------------------------------------------------------------------------------------" << endl;
    return ss.str();
}

void Livro::exibeIndiceAlfabetico(){
    cout << "Indice Remissivo por ordem alfabetica: " << endl;
    cout << livroPagina.imprimePalavrasPagina();
}

void Livro::exibeIndiceNumerico(){
    cout << ordenaNumero();
}

void Livro:: exibeMaiorParicao(){
    cout << "Palavras com maior quantidade de ocorrencia: " << endl;
    cout << maiorAparicao();
}
void Livro::exibepesquisaPalavra(string palavra){
    cout << pesquisaPalavra(palavra);
}
void Livro::exibepesquisaTotal(string palavra , int pagina){
    stringstream ss;
    ss << "Pesquisa da palavra: " << palavra << " na pagina: " << pagina << endl;
    ss << "-----------------------------------------------" << endl;
    ss << "| Ocorrencias: ";
    ss << GREEN << pesquisaTotal(palavra, pagina) << RESET;
    ss << " |" << endl;
    ss << "-----------------------------------------------" << endl;
    cout << ss.str();
}
string Livro:: maiorAparicao(){
    Palavra *ptr = livroSemPagina.header->next;
    int maior = 0;
    stringstream ss;
    ss << "---------------------------------------------" << endl;
    while (ptr != nullptr){
        if (ptr->quantPalavras > maior){
            maior = ptr->quantPalavras;
        }
        ptr = ptr->next;
    }
    ptr = livroSemPagina.header->next;
    ss << "| Quantidade de Ocorrencias: " << maior << " |" << endl;
    while (ptr != nullptr){
        if (ptr->quantPalavras == maior){
            ss << "| " << RED << ptr->palavra << RESET << " |" << endl;
        }
        ptr = ptr->next;
    }
    ss << "--------------------------------------------" << endl;
    return ss.str();
}

void Livro::clearConsole(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

double Livro::percentual(){
    int quantidadeTotalPalavras= totalStopWords();
    int quantidadeRegistradas = totalPalavras();
    quantidadeTotalPalavras += quantidadeRegistradas;
    double percentual = (static_cast<double>(quantidadeRegistradas) / quantidadeTotalPalavras) * 100.0;
    return percentual;

}

int Livro::palavrasDiferentes(){
    return livroSemPagina.getTamanhoVetor();
}

int Livro::totalPalavras(){
    int quantidadeRegistradas =0;
    for(int i = 0; i < livroSemPagina.getTamanhoVetor();i++){
        quantidadeRegistradas += livroSemPagina.getOcorrencia(i);
    }
    return quantidadeRegistradas;
}
int Livro::totalStopWords(){
    int quantidadeTotalPalavras= 0;
    for(int i =0; i< Stopwords.getTamanhoVetor(); i++){
      
        quantidadeTotalPalavras += Stopwords.getOcorrencia(i);
    }
    return quantidadeTotalPalavras;
}

void Livro::exibirInfoCatalogacao(){
    stringstream ss;
    ss << "Informacoes sobre Catalogacao: " << endl;
    ss << "--------------------------------------------" << endl;
    ss << GREEN << "| Percentual relativo: " << fixed << setprecision(2) << percentual() << "% |" << RESET << endl;
    ss << "| Numero de palavras diferentes: " << palavrasDiferentes() << " |" << endl;
    ss << "| Total de palavras: " << totalPalavras() << " |" << endl;
    ss << RED << "| Total de stopwords: " << totalStopWords() << " |" << endl << RESET ;
    ss << "--------------------------------------------" << endl;
    cout << ss.str();
}

int Livro::pesquisaTotal(string palavra , int pagina){
    for(int i = 0; i < livroPagina.getTamanhoVetor() ; i++){
        if(livroPagina.getPalavra(i) == palavra && livroPagina.getPagina(i) == pagina){
            
            return livroPagina.getOcorrencia(i);
        }
    }
    return 0;
     
}
string Livro::pesquisaPalavra(string palavra){
    stringstream ss;
     Palavra *ptr = livroPagina.header->next;
     ss << "Palavra pesquisada e suas ocorrencias: " << endl;
     ss << "------------------------------------------" << endl;
      ss << "| " << ORANGE << palavra << RESET << " |" << endl;
      ss << "| Paginas: ";
     while (ptr != nullptr){
        if(ptr->palavra == palavra){
            ss << ptr->pagina << " ";
        }
        ptr = ptr->next;
     }
     ss << "|";
     ss << endl;
     ss << "------------------------------------------" << endl;
     return ss.str();
}