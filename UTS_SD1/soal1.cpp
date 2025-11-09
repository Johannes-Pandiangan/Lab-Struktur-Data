#include <iostream>
#include <vector>
using namespace std;

// Struktur data pasien
struct Pasien {
    string nama, jenis;
    int umur, darurat, urutan;
};

// Fungsi untuk menukar posisi 2 pasien
void tukar(Pasien &a, Pasien &b) {
    Pasien temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk mengurutkan data pasien (Bubble Sort)
// Dengan aturan:
            // 1. Darurat tinggi lebih dulu
            // 2. Jika darurat sama, yang datang duluan (urutan kecil) lebih dulu
void urutkanPasien(vector<Pasien> &antrian) {
    int n = antrian.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (antrian[j].darurat < antrian[j + 1].darurat || //jika tingkat darurat antrian yang didepan lebih kecil
                //jika tingkat darurat sama, dan urutan antrian yang didepan lebih besar:
               (antrian[j].darurat == antrian[j + 1].darurat && antrian[j].urutan > antrian[j + 1].urutan)) {
                tukar(antrian[j], antrian[j + 1]); //tukar posisi antrian, agar sesuai aturan
            }
        }
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah pasien: ";
    cin >> n;

    vector<Pasien> antrian;

    // Input data pasien
    for (int i = 0; i < n; i++) {
        Pasien p;
        cout << "\nPasien " << i + 1 << ":\n";
        cout << "Nama hewan: ";
        cin >> ws; getline(cin, p.nama);
        cout << "Jenis hewan: ";
        getline(cin, p.jenis);
        cout << "Umur: ";
        cin >> p.umur;
        cout << "Tingkat darurat (1-5): ";
        cin >> p.darurat;
        p.urutan = i;
        antrian.push_back(p); // Tambahkan pasien ke antrian
    }

    // Urutkan pasien dengan bubble sort agar sesuai aturan
    urutkanPasien(antrian);

    // Tampilkan hasil urutan penanganan
    cout << "\n=== DAFTAR PENANGANAN ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << antrian[i].nama
             << " (" << antrian[i].umur << " tahun)"
             << " - Darurat " << antrian[i].darurat << endl;
    }

    return 0;
}