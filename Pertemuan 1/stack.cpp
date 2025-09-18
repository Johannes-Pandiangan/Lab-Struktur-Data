#include<iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

//push : tambah stack
void push (int value) {
    if (top==MAX-1){ //memeriksa isi stack
        cout << "Stack penuh!\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " ditambahkan dalam stack\n";
    }
}

//pop : hapus stack
void pop(){
    if (top==-1){ //mengecek isi stack
        cout << "Stack Kosong!\n";
    } else {
        cout << "\n" << stack[top] << " dihapus dari stack.\n";
        top--; 
    }
}

//menampilkan stack
void display(){
    if(top==-1){ //mengecek isi stack
        cout<<"Stack kosong!\n";
    } else {
        cout << "\nISi Stack : \n"; //menampilkan isi stack
        for (int i=top;i>=0;i--){
            cout << stack[i] <<" ";
        }
    }
}

int main(){
    system("cls");
    //masukkan isi stack:
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);

    //menampilakn dan manghapus isi stack
    display();
    pop();
    display();

    return 0;
}
