#include<iostream>
using namespace std;

int main() {
    int n;
    //user menginput sendiri berapa jumlah array yang diinginkan
    cout << "Masukkan jumlah elemen array:";
    cin >> n;

    int* arr = new int[n]; //n menjadi banyaknya jumlah array

    cout<<"Masukkan "<<n<< " angka: \n"; //memasukkan isi array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Isi Array : "; //menampilkan isi array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    delete[] arr; //menghapus array yang tidak digunakan agar tidak membuat loss memory
    return 0;
}