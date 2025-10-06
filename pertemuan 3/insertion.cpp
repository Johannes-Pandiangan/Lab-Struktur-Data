// Program Insertion Sort
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Insertion Sort dari terkecil hingga terbesar
    for (int i=1; i<n;i++){ 
        int key = data[i]; //key adalah elemen yang akan ditempatkan pada posisi yang tepat
        int j=i-1; //j adalah tepat 1 elemen sebelum key

        while(j>=0 && data[j]>key){ // Geser elemen yang lebih besar dari key ke kanan
            data[j+1]=data[j]; // Pindahkan elemen data[j] ke posisi j+1
            j--; // Geser ke kiri untuk lanjut membandingkan
        }
        data[j+1]=key; // Tempatkan key di posisi yang sudah benar
    }

    
    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    
    cout << endl;
    return 0;
}