//Tugas implementasi stack dengan linked list, 
//lalu push 3 angka dan pop 1 angka
#include <iostream>
using namespace std;

//deklarasi sebuah struktur node
struct Node {
    int value;
    Node* next;
};

// Top dari stack
Node* top = NULL;

// Fungsi push: tambah ke atas stack
void push(int n) {
    Node* newNode = new Node;
    newNode->value = n;
    newNode->next = top; 
    top = newNode;
    cout << n << " ditambahkan dalam stack\n";
}

// Fungsi pop: hapus dari atas stack
void pop() {
    if (top == NULL) {
        cout << "Stack kosong\n";
        return;
    }
    cout << top->value << " dihapus dari stack\n";
    Node* temp = top;
    top = top->next; 
    delete temp;
}

// Fungsi untuk menampilkan isi stack dalam bentuk linked list
void display() {
    if (top == NULL) {
        cout << "Stack kosong.\n";
        return;
    }
    cout << "Isi stack: ";
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n\n";
}

int main() {
    //Push 3 angka
    push(10);
    push(20);
    push(30);

    display();

    //Pop 1 angka
    pop();

    display();
    return 0;
}
