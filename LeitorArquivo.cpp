// Iaçanã Ianiski Weber - 09/2023
/*Como identificar que ja se passaram 2500 caracteres*/
#include <iostream>
#include "LeitorArquivo.h"
using namespace std;

bool LeitorArquivo::isSpecialChar(char c){
    return !std::isalpha(c);
}

LeitorArquivo::LeitorArquivo(string nome):file(nome){
    if(!file){
        throw std::runtime_error("Could not open file: " + nome);
    }
    numCharac = 0;
}


//Alem de passar para a proxima palavra incrementa na variavel de contagem de caracteres

string LeitorArquivo::proximaPalavra(){
    std::string word = "";
    // read characters until a space is found
    for (char c; file.get(c); ) {
        if (std::isspace(c)) {
            if (!word.empty()) {
                // end of a word, return it
                numCharac++;
                return word;
            }
            numCharac++;
        } else if (!isSpecialChar(c)) {
            // not a special character, add it to the word
            word += c;
            numCharac++;
        } else {
            numCharac++;
        }
    }
    // end of file or error, return what has been read
    return word;
}

int LeitorArquivo::getNumCharac(){
    return numCharac;
}