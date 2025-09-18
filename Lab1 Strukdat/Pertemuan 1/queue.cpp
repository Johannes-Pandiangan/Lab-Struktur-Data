#include<iostream>
using namespace std;

#define MAX 6
int queue[MAX];
int front = -1, rear = -1;

//enqueue : memasukkan isi queue
void enqueue(int value){
    if(rear == MAX -1) { //mengecek isi queue
        cout<<"Queue Penuh!\n";
    } else {
        if(front == -1) front=0;
        rear++;
        queue[rear] = value;
        cout << value << " masuk ke queue.\n";
    }
}

//dequeue : menghapus isi queue
void dequeue() {
    if (front == -1 || front > rear) { //mengecek isi queue
        cout << "Queue Kosong !\n";
    } else {
        cout  << queue[front] << " Keluar dari Queue\n";
        front++;
    }
}

//menampilkan queue
void display() {
    if (front == -1 || front > rear){ //mengecek isi queue
        cout << "Queue kosong !\n";

    } else {
        cout << "\nIsi Queue: ";
        for (int i=front;i<=rear;i++)
        cout << queue[i]<<" ";
    }
    cout << endl;
}

int main() {
    system("cls");
    //masukkan isi queue
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    
    display(); //tampilakn isi queue

    enqueue(6);
    display();

    dequeue(); //menghapus isi queue
    display();

    return 0;
}