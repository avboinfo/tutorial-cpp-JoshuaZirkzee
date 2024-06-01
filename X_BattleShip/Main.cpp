#include<iostream>
#include"BattleShip.cpp"
using namespace std;

int main(){

    cout << "Gioco della battaglia navale -  Buon divertimento" << endl;
    BattleShip gioco = BattleShip();
    gioco.play();
    return 0;
    cout << "GAME OVER!";
}