// Program Selection Sort
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Selection Sort dari terbesar hingga terkecil
    for (int i = 0; i < n - 1; i++) { 
        int maxIndex = i; //data paling besar ditetapkan sebagai maxindex
        for (int j = i + 1; j < n; j++) { 
            if (data[j] > data[maxIndex]) { //jika ada data yang lebih besar daripada maxindex tadi
                maxIndex = j; //maka dia akan ditetapkan sebagai maxindex yang baru
            }
        }
        //bertukar tempat agar sesuai urutan (dari besar ke kecil)
        int temp = data[i];
        data[i] = data[maxIndex];
        data[maxIndex] = temp;
        //lalu ulangi dan lanjut ke index berikutnya untuk menentukan data terbesar selanjutnya setelah yang tadi
        //begitu seterusnya hingga semua sudah terurut
    }


    cout << "Data setelah diurutkan dari terbesar hingga terkecil:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}