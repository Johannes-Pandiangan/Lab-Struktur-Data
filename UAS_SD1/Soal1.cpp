#include<iostream>
using namespace std;


// ga ngerti sama sekali yang nomor satu kak, skip ajalah langsung ke nomor 2 & 3 kak hehe:)
int main(){
    system("cls");
    int n, pi;
    cin >> n;
    if (n < 1 || n > 2000) {
        return 0;
    }

    for (int i = 0; i<n; i++) {
        cin >> pi;
    //jika pi bernilai -1 maka tidak memiliki menejaer langsung
        if (pi == -1) {
        
    //jika pi bernilai antara 1 dan n maka memiliki menejaer langsung
        } 
        if (pi >= 1 && pi <= n) {
            cout << pi << " " << endl;
        }
    }
}