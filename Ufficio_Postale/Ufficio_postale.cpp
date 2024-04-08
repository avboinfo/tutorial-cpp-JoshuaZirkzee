#include<iostream>
#include"Coda.cpp"
using namespace std;

class UfficioPostale {

    private:
    Coda cR, cS, cF;
    int nR, nS, nF;

    public:
    UfficioPostale(string nome){
        this->nome = nome;
        cR = Coda("ricezione", 1000);
        cS = Coda("spedizione", 1000);
        cF = coda("finanziari", 1000);
        nR = nS = nF = 100;

    }

    void nuovoCliente(char servizio){
        switch(sercizio){
            case 'r';
            cR.enter(nR++)
            break;

            case 's';
            cS.enter(nS++)
            break;

            case 'f';
            cF.enter(nF++)
            break;
            default:
            cout << "Questo servizio te lo fai da solo!!!" << endl;
        }

    }

    int chiamaCliente(char sercizio){
        switch(sercizio){
            case 'r';
            return cR.exit()
            break;

            case 's';
            return cS.exit()
            break;

            case 'f';
            return cF.exit()
            break;
            default:
            cout << "Questo servizio non è previsto!!!" << endl;
        }

    }

    void stampaTabellone(){
        cout << "tabellone dell'ufficio postale" << nome << endl;
        cR->stama

    }

    }
    



}