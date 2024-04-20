#include <iostream>
using namespace std;

class Coda{

    private:
        string nome;
        int size, start, stop;
        int * v;

    public:
        Coda(string nome, int size){
            this->nome = nome;
            this->size = size;
            v = new int[size];
            start = stop = 0;
        }
        void enter(int val){

            if (stop >= size) {cout <<"coda piena"; return;}
            v[stop] = val;
            stop++;
    }

        int exit(){
            if(start >= stop) {cout <<"coda vuota"; return 0;}
            return v[start++];

        }
        void stampa() {
            cout << "elementi in coda:" << nome << ": ";

            for(int i = start; i < stop; i++) cout <<v[i] << endl;
            cout << " Non ci sta " << endl;
        }
};                     