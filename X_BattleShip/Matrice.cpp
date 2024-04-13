#include<iostream>
using namespace std;

class Matrice {

    private:
    int m[10][10];

    public:
    Matrice(int n) {
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                m[i][j] = n;

            }
        }
    }

    void stampa(){
        cout << endl << "--------------------------------" << endl;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                cout << m[i][j] << "\t";
            }
                cout << endl;
        }
        cout << endl << "--------------------------------" << endl;
    }
};


int main(){
    Matrice m1 = Matrice( 3 );
    m1.stampa();
}