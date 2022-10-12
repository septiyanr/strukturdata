#include<iostream>
using namespace std;
#define MAX 8

struct Antrian {
    int data[MAX];
    int head;
    int tail;
};

Antrian antre;
void create();
bool isEmpty();
bool isFull();
void enqueue(int);
int dequeue();
void tampil();
void menu();

int main(){

    create();
    menu();

    return 0;
}

void create(){
    antre.head = antre.tail =-1;
}

bool isEmpty(){
    if(antre.tail == -1){
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(){
    if(antre.tail == MAX - 1){
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int data){
    if(isEmpty()){
        antre.head = antre.tail = 0;
        antre.data[antre.tail] = data;
    }
    else
    {
        antre.tail++;
        antre.data[antre.tail] = data;
    }
    cout<<data<<" dimasukkan ke antrian";
}

int dequeue(){
    int i;
    int e = antre.data[antre.head];
    for(i = antre.head;i < antre.tail;i++){
        antre.data[i] = antre.data[i+1];
    }
    antre.tail--;
    return e;
}

void tampil(){
    if(isEmpty()){
        cout<<"data kosong";
    }
    else{

        for(int i = antre.head;i <= antre.tail;i++){
            cout << antre.data[i] << " ";
        }
    }
}

void menu()
{

    int opsi, angka;


    do{

        cout << "MENU" << endl;
        cout << "1. Masukan antrian" << endl;
        cout << "2. Hapus 1 antrian" << endl;
        cout << "3. Tampilkan antrian" << endl;
        cout << "4. Status antrian" << endl;
        cout << "\n------------------------\n" << endl;
        cout << "Pilih menu : ";cin>>opsi;


        switch (opsi)
        {
        case 1:
            cout << "Isi nomor antrian ";cin>>angka;
            enqueue(angka);
            cout << "\n------------------------\n" << endl;
            break;
        case 2:
            cout << "Antrian " << dequeue() << " selesai" << endl;
            cout << "\n------------------------\n" << endl;
            break;
        case 3:
            if (isEmpty()!=true)
            {
                cout << "Antrian yang masih tersedia ";tampil();
                cout << "\n------------------------\n" << endl;
            }
            else{
                cout << "Masih kosong" << endl;
                cout << "\n------------------------\n" << endl;
            }

            break;
        case 4:
            if (isFull())
            {
                cout << "Antrian telah penuh! " << endl;
                cout << "\n------------------------\n" << endl;
            }
            else if(isEmpty())
            {
                cout << "Antrian masih kosong! " << endl;
                cout << "\n------------------------\n" << endl;
            }
            else{
                cout << "Ada isinya tapi tidak penuh" << endl;
                cout << "\n------------------------\n" << endl;
            }
            break;




        }



    }while(opsi!=5);


}

