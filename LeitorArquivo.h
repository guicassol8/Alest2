// Iaçanã Ianiski Weber - 09/2023
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

#ifndef _LEITOR_ARQUIVO_
#define _LEITOR_ARQUIVO_
// ****************************
class LeitorArquivo{
private:
    ifstream file;
    bool isSpecialChar(char c);
    int numCharac;
public:
    LeitorArquivo();
    LeitorArquivo(string nome);
    string proximaPalavra();
    int getNumCharac();
    void zeraNumCharac();
};

#endif


