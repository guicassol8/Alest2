// Iaçanã Ianiski Weber - 09/2023
#include <iostream>
#include <cstdlib>
#include "LeitorArquivo.h"

using namespace std;

int main() {
    LeitorArquivo a = LeitorArquivo("Livros/alice.txt");

    int count = 0;
    while(1){
        string b = a.proximaPalavra(); 
        cout << b << endl;
        count++;
        if(b.empty()){
            break;   
        }
    }

    cout << "Counter: " << count << endl;
    return 0;
}