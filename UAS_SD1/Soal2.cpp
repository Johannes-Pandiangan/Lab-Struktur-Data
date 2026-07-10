#include <iostream>
#include <algorithm>
#include <math.h>    
using namespace std;

int main() {
    system("cls");
    int N;

    cin >> N;
    if (N < 1 || N > 200) {
        cout << "Jumlah Kursi bioskop hanya terdapat 200"<<endl;
        return 0;
    }

    int data[N];
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    int cari;
    cin >> cari;

    int low = 0, high = N - 1, flag = 0;
    int posisi;
    float posisi1;

    // Proses Interpolation Search
    while(low <= high && cari >= data[low] && cari <= data[high]) {
        posisi1 = (float)(cari - data[low]) / (data[high] - data[low]) * (high - low) + low;
        posisi = floor(posisi1);

        if (data[posisi] == cari) {
            flag = 1;
            break;
        }
        
        if (data[posisi] > cari) 
            high = posisi - 1;
        else 
            low = posisi + 1;
    }
    
    cout << "\nMencari Kursi No: " << cari << endl;
    if (flag == 1) {
        cout << "Status: TERSEDIA " << endl;
        cout << "Detail: Ditemukan pada index [" << posisi << "]" << endl;
    } else {
        cout << "Status: TIDAK TERSEDIA" << endl;
        cout << "Opsi: Kursi terdekat yang tersedia adalah No.";

        int kursiTerdekat = -1;
        for (int i = 0; i < N; i++) {
            if (data[i] > cari) {
                kursiTerdekat = data[i];
                break;
            }
        }
        if (kursiTerdekat != -1) {
            cout << kursiTerdekat << endl;
        }
    }
    return 0;
}