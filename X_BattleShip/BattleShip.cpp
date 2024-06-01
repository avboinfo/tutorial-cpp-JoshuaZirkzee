#include <iostream>

#include "BattleField.cpp"

using namespace std;


class BattleShip{

    private:
    BattleField mappa;
    BattleField campo;


    public: 
    BattleShip(){
        srand(time(NULL));
        mappa = BattleField( VOID );
        campo = BattleField( VOID );
        campo.placeHorizontalShip(3); 
        campo.placeVerticalShip(4);
        campo.placeVerticalShip(2);
        campo.placeHorizontalShip(5);
        

    }
   

    void play(){
        //lancia 20 bombe a caso
        while(true){
            mappa.stampa();
            if( !playHand()) break;
  
        }

        
        campo.stampa();
    }

    bool playHand(){
        cout<<"Inserisci le cordinate di riga e colona(1-"<<DIM<<") in cui sganciare la bomba";
        int x, y;
        cin>>x; if (x == 0 || x > DIM) return false; else x--;
        cin>>y; if (y == 0 || y > DIM) return false; else y--;
        if(x<=0)
            return false; else x--;
        if(y<=0)
            return false; else y--;
            
        
        if(campo.get(x,y)==SHIP) {
                mappa.put(x,y,HIT);
                campo.put(x,y,HIT);
            } else mappa.put(x,y,MISS);
        }
    bool Gameover(){
            
            for (int i = 0; i < DIM; i++) {
                for (int j = 0; j < DIM; j++) {
                    if (campo.get(i, j) == SHIP) {
                        return false;
                    
                }
            }
            return true;
        }

        }
    };

