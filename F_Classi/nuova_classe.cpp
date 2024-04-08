#include <iostream>
using namespace std;

class Vettore {
private:
    int dim, len, delta;
    public: int * v;
public:
    Vettore(int dim, int delta) {
        this->dim = dim;
        this->delta = delta;
        len = 0;
        v = new int[dim];
    }

    void add(int n){
        if(len == dim) {
            int *nuovov = new int[dim + delta];
            for(int i = 0; i < dim; i++) nuovov[i] = v[i];
            dim += delta;
            delete[] v; 
            v = nuovov;
        }
        v[len] = n;
        len++;
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

   ~Vettore() {
        delete[] v; 
    }
};

int main(int argc, char * argv[]){
    Vettore vett(10, 10);
    for(int i = 0; i < 100; i++) vett.add(i);
    vett.getElement(10) << endl;
    vett.setElement( 10, 333);

    vett.print();
}