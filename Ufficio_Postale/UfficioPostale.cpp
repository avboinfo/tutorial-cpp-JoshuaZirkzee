#include <iostream>
#include "Coda.cpp"
using namespace std;

class UfficioPostale
{

private:
    Coda cR = Coda("ricezione", 1000);
    Coda cS = Coda("spedizione", 1000);
    Coda cF = Coda("finanziari", 1000);
    int nR = 0, nS = 0, nF = 0;
    string nome;

public:
    UfficioPostale(string nome)
    {
        this->nome = nome;
    }

    void nuovoCliente(char servizio)
    {
        switch (servizio)
        {
        case 'r':
            cR.enter(nR++);
            break;

        case 's':
            cS.enter(nS++);
            break;

        case 'f':
            cF.enter(nF++);
            break;
        default:
            cout << "Questo servizio te lo fai da solo!!!" << endl;
        }
    }

    int chiamaCliente(char sercizio)
    {
        switch (sercizio)
        {
        case 'r':
            return cR.exit();
            break;

        case 's':
            return cS.exit();
            break;

        case 'f':
            return cF.exit();
            break;
        default:
            cout << "Questo servizio non è previsto!!!" << endl;
        }
    }

    void stampaTabellone()
    {
        cout << "tabellone dell'ufficio postale" << nome << endl;
    }
};