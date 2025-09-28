#include<iostream>
using namespace std;

//deklarasi sebuah struktur node
struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL; //menandakan bahwa linked list masih kosong

//insert di depan
void insertFirst(int n) {
    Node *newNode = new Node; //membuat node baru yang siap diisi
    newNode -> value = n;
    newNode -> next =NULL;

    //menambahkan node pada bagian depan
    if (head==NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode -> next = head;
        head = newNode;
    }
}

//insert di belakang
void insertLast(int n) {
    Node *newNode = new Node; //membuat node baru yang siap diisi
    newNode -> value = n;
    newNode -> next =NULL;

    //menambahkan node pada bagian belakang
    if(head==NULL) {
        head=newNode;
        tail=head;
    } else {
        tail -> next =newNode;
        tail = newNode; 
    }   
}

//insert setelah node dengan nilai tertentu
void insertAfter(int n,int check) {
    if (head==NULL){
        cout<<"List Kosong, insert di depan dulu\n";
        return;
    }
    Node *newNode = new Node; //membuat node baru yang siap diisi
    newNode -> value = n;
    newNode -> next =NULL;

    //mencari dimana tempat untuk menambah node tersebut
    Node *p=head;
    while(p != NULL && p->value != check) {
        p = p-> next;
    }

    //menambahkan node ditempat yang ditentukan
    if (p== NULL) {
        cout<<"Node dengan nilai "<< check <<" Tidak ditemukan\n";
        delete newNode;
    } else {
        newNode -> next = p -> next;
        p -> next = newNode;
        if (p==tail) {
            tail=newNode;
        }
    }
}

//cetak linked list
void printList() {
    Node *temp = head;
    cout << "Isi dari Linked list : ";
    while(temp != NULL) {
        cout << temp -> value <<" -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

int main () {
    insertFirst(10);
    insertLast(20);
    insertLast(30);
    insertAfter(25, 20);
    insertFirst(5);

    printList();
    return 0;
}