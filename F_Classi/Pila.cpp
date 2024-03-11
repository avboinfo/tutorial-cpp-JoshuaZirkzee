#include <iostream>
using namespace std;

class Pila {
private:
    int size, len, delta;
    public: int * v;
public:
    Pila(int dim, int delta) {
        this->size = size;
        this->delta = delta;
        len = 0;
        v = new int[size];
    }

    void push(int n){
        if(len == size) {
            int *nuovov = new int[size + delta];
            for(int i = 0; i < size; i++) nuovov[i] = v[i];
            size += delta;
            delete[] v; 
            v = nuovov;
        }
        v[len] = n;
        len++;
    }
int pop(){
    if (len==0) {cout << "\nERRORE Pila Vuola\n"; return 0;}
    
    int result = v[len-1];
    len--;
    return result;
}

int getElement( int index ){
    return v[index];
}

void setElement( int index, int newvalue ){
    v[index] = newvalue;
}
    void print(){
        cout << "contenuto del vettore: ";
        for(int i = 0; i < len; i++) cout << v[i] << " ";
        cout << endl;
    }

   Pila() {
        delete[] v; 
    }
};

int main(int argc, char * argv[]){
    Pila vett(10, 10);
    for(int i = 0; i < 100; i++) vett.push(i);
    cout << vett.getElement(10) << endl;
    vett.setElement( 10, 333);

    vett.print();

    for(int i = 0; i < 10; i++) {
        cout << vett.pop() << " ";
    }
}