#include <iostream>
using namespace std;

// fungsi untuk menukar dua buah elemen
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}


// fungsi untuk memilih pivot
int partition(int arr[], int low, int  high){
    int pivot = arr[low]; //pivot yang ini dipilih dari index paling depan
    int i = low; 
    int j = high;

    while(true){
        // Geser i ke kanan selama elemen <= pivot
        while(i<=high && arr[i]<=pivot)
        i++;

        // Geser j ke kiri selama elemen > pivot
        while(j>=low && arr[j]>pivot)
        j--;

        // Jika pointer i melewati pointer j, berarti pembagian selesai
        if(i > j){
            break;
        }
        swap(arr[i], arr[j]);// tukar elemen agar sesuai dengan ketentuan urutan
    }
    swap(arr[low],arr[j]); // Tempatkan pivot di posisi yang benar
    return j; // Kembalikan index pivot yang baru
}

// fungsi rekursif
void quickSort(int arr[], int low, int high){
    if(low<high) {
        int pivotIndex = partition(arr, low, high);// Bagi array berdasarkan pivot

        //panggil quick sort
        quickSort(arr, low, pivotIndex-1); // Rekursif untuk bagian kiri pivot
        quickSort(arr,pivotIndex+1,high); // Rekursif untuk bagian kanan pivot
    }
}


int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Panggil fungsi Quick Sort untuk mengurutkan data
    quickSort(data, 0, n - 1);

    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}