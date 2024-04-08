#include <iostream>
#include "Classe.cpp"
using namespace std;


int main(){
    Poste prova = Poste(1000);
    string s;
    int c = 0;
    int end = 0;
    int i = 1;


    while(end != 1){

        cin>>c;

        if (c == 1){
            cin>>s;
            prova.Enter(i, s);
        }
        if (c == 2){

        }
        if (c == 3){
            cin>>s;
            prova.print(s);
        }
    }

    prova.print(s);
}
