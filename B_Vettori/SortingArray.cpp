/*Montanari. Alessandro.
10/02/2024
Riordinamento bubbleSort e quickSort*/

#include <iostream>
#include <fstream>

using namespace std;
const string FILENAME = "SortingArray.txt";
int numeroScambi = 0;

void stampaVettore( string v[], int l ) {
    cout << endl;
    for (int i=0; i<l; i++) cout << v[i] << "\n";
    cout << endl;
}

int bubbleSort( string v[], int l ) {
    int numOp = 0;
    string tmp;
    for (int i=0; i<l; i++ ) {
        bool alreadySorted = true;
        for (int j=0; j<l-1; j++ ) {
            if ( v[j] > v[j+1] ) {
                alreadySorted = false;
                tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
            numOp++;
        }
        if (alreadySorted) break;
    }
    return numOp;
}
void swap(string arr[] , int pos1, int pos2){
	string temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(string arr[], int low, int high, string pivot){
	int i = low;
	int j = low;
	while( i <= high){
		if(arr[i] > pivot){
			i++;
		}
		else{
			swap(arr,i,j);
			i++;
			j++;
		}
	}
	return j-1;
}

void quickSort(string arr[], int low, int high){
	if(low < high){
	string pivot = arr[high];
	int pos = partition(arr, low, high, pivot);
	
	quickSort(arr, low, pos-1);
	quickSort(arr, pos+1, high);
	}
}
int main()
{
    ifstream f;
    f.open(FILENAME);
    if ( f.fail() ) { cout << "Il file di input non esiste"; return -1; }
    
    int n;
    string s;
    for (n=0; getline(f,s); n++);
    f.close();
    cout << "il file di input contiene " << n << " righe" << endl;
    
    string vs[n];
    f.open(FILENAME);
    for (int i=0; i<n; i++) getline( f, vs[i] );

    stampaVettore(vs, n);
    numeroScambi=0;
    //quickSort(vs, 0, n-1);
    numeroScambi=bubbleSort(vs, n);
    cout << "Eseguiti " << numeroScambi << " scambi." << endl;
    stampaVettore(vs, n);

    return 0;
}



