/*
Nama: Johannes Indra Christian Pandiangan
NIM: 241401001
*/

#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencetak papan Sudoku
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) {
                cout << " ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

// Fungsi untuk memeriksa apakah sebuah angka valid di posisi tertentu
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Periksa baris dan kolom
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Periksa sub-kotak 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Fungsi utama pemecah Sudoku menggunakan rekursif DFS
bool solveSudoku(vector<vector<int>>& board) {
     // Cari sel kosong
        // Ketemu sel kosong
            // Coba masukkan angka dari 1 - 9
                // Jika valid (gunakan fungsi isValid):
                    // Masukkan angka
                    // Rekursi
                // Jika gagal:
                    // kosongkan sel
            // Jika tidak ada angka yg valid, backtrack (return false)
    // Jika tidak ada lagi sel kosong (solusi telah ditemukan), return true
//=============================================================================================================
//Jawaban:
    // Cari sel kosong:
     for (int row = 0; row < 9; row++) { //untuk semua baris
        for (int col = 0; col < 9; col++) { //untuk semua kolom
            // Ketemu sel kosong:
            if (board[row][col] == 0) { //jika ketemu sel kosong
            // Coba masukkan angka dari 1 - 9:
            for (int num = 1; num <= 9; num++) { //dimasukkan pake perulangan saja
                // Jika valid (gunakan fungsi isValid):
                 if (isValid(board, row, col, num)) {
                     board[row][col] = num;// Masukkan angka
                    // Rekursi:
                     if (solveSudoku(board)) {
                            return true; // Lanjutkan jika berhasil
                        }
                // Jika gagal:
                  board[row][col] = 0; // kosongkan sel
                    }
                }
                // Jika tidak ada angka yg valid, backtrack (return false):
                return false;
            }
        }
    }
    // Jika tidak ada lagi sel kosong (solusi telah ditemukan), return true:
    return true;
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    

    cout << "Papan Sudoku awal:" << endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "Papan Sudoku terpecahkan:" << endl;
        printBoard(board);
    } else {
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }

    return 0;
}