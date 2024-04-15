#include<iostream>
using namespace std;

const int DIM = 10;

class Matrice {

    private:
    char m[DIM][DIM];

    public:
    Matrice(){
        for(int i=0; i<DIM; i++){
            for(int j=0; j<DIM; j++){
                m[i][j] = 97 + rand()%26;
        }
     }
}
    Matrice(int n) {
        for(int i=0; i<DIM; i++){
            for(int j=0; j<DIM; j++){
                m[i][j] = n;

            }
        }
    }

char get(int x, int y){
    return m[x][y];
}

void get(int x, int y, char c){
    return m[x][y] = c;
}
    void stampa(){
        cout << endl << "--------------------------------" << endl;
        for(int i=0; i<DIM; i++){
            for(int j=0; j<DIM; j++){
                printf("%c ", m[i][j]);
            }
                cout << endl;
        }
        cout << endl << "--------------------------------" << endl;
    }


void bomb(){
    int x = rand() % DIM;
    int y = rand() % DIM;
    m[x][y] = '*';
}

void placeHorizontalShip(int len){
    if(len <= 0 || len >=DIM) return;
    int x = rand() % DIM;
    int y = rand() % (DIM - len);
    for ( int i = 0; i < len; i++) m[x][y+i] = '0';
}

void placeVerticalShip(int len){
    if(len <= 0 || len >=DIM) return;
    int x = rand() % (DIM - len);
    int y = rand() % DIM;
    for ( int i = 0; i < len; i++) m[x + 1][y] = '0';
}

};

int main(){
    srand(time(NULL));
    Matrice mappa = Matrice( '_' );
    Matrice campo = Matrice('.');

    campo.placeHorizontalShip(3);
    campo.placeVerticalShip(4);
    campo.placeVerticalShip(2);
    campo.placeHorizontalShip(5);

    for(int i = 0; i<20;i++){
        int x = rand() % DIM;
        int y = rand() % DIM;
        if(campo.get(x,y)=='0') mappa.put(x,y,'*')
    }
    mappa.stampa();
}