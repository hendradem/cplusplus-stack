#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#define max 10
int top;


// struct section
struct PROSES{
    int id;
    string hasil;
};
struct mahasiswa {
    int nim;
    string nama;
    string prodi;
    string ipk;
    PROSES proses;
} mhs[max];

// stack section
void init(){
    top = -1;
}

bool isEmpty(){
    if(top <= 0 ){
        return true;
    } else {
        return false;
    }
}

bool isFull(){
    if(top == max - 1){
        return true;
    } else {
        return false;
    }
}

void push(int nim, string nama, string prodi, string ipk, string nilaiAkhir ){
    if(isFull()){
        cout<<"Data sudah penuh";
    } else {
        top++;

        if( ipk == "0" ){
            nilaiAkhir = "E";
        } else if( ipk > "1.00" && ipk < "2.00" ){
            nilaiAkhir = "D";
        } else if( ipk > "2.00" && ipk < "2.67" ){
            nilaiAkhir = "C";
        } else if( ipk > "2.67" && ipk < "3.00" ){
            nilaiAkhir = "B";
        } else if( ipk > "3.00" && ipk <= "3.67" ){
            nilaiAkhir = "A";
        } else if( ipk > "3.67" && ipk <= "4.00" ){
            nilaiAkhir = "A";
        }

        mhs[top].nim   = nim;
        mhs[top].nama  = nama; 
        mhs[top].prodi = prodi; 
        mhs[top].ipk   = ipk;
        mhs[top].proses.hasil   = nilaiAkhir;

        
        
    }
}

void pop(){
    if(isEmpty()){
        cout<<"Data stack kosong";
    } else {
        cout<<"Nama      : " <<mhs[top].nama <<endl;
        cout<<"NIM       : " <<mhs[top].nim  <<endl;
        cout<<"prodi     : " <<mhs[top].prodi <<endl;
        cout<<"IPK       : " <<mhs[top].ipk <<endl;
        cout<<"Hasil     : " <<mhs[top].proses.hasil <<endl;
        top--;
    }
}

void show(){
    if(isEmpty()){
        cout<<"Data stack kosong";
    } else {
        for(int i=1; i<top+1; i++){
            cout<<"Nama      : " <<mhs[i].nama <<endl;
            cout<<"NIM       : " <<mhs[i].nim  <<endl;
            cout<<"prodi     : " <<mhs[i].prodi <<endl;
            cout<<"IPK       : " <<mhs[i].ipk <<endl;
            cout<<"Hasil     : " <<mhs[top].proses.hasil <<endl;
        }
    }
}

int main(){

int menu, data, nim; string nama, prodi, ipk, nilaiAkhir;

menu : 
system("clear");

cout<<"Silahkan pilih menu dibawah" <<endl <<endl;
cout<<"1. Push" <<endl;
cout<<"2. Pop" <<endl;
cout<<"3. Show" <<endl;
cout<<"4. Delete" <<endl;
cout<<"5. Exit" <<endl;

cout<<"Masukkan menu yang anda pilih : "; cin>>menu;

switch(menu){
    case 1:
        cout<<"Masukkan Nama Mahasiswa  : "; cin.ignore(); getline(cin, nama);
        cout<<"Masukkan NIM             : "; cin>>nim;
        cout<<"Masukkan Prodi Mahasiswa : "; cin.ignore(); getline(cin, prodi);
        cout<<"Masukkan IPK Mahasiswa   : "; cin>>ipk;
        push(nim, nama, prodi, ipk, nilaiAkhir);

        goto menu;
    break;
    case 2:
        pop();
    break;
    case 3:
        show();
    break;
    case 4:
        init();
    break;
    case 5:
        system("exit");
    break;



}



    

}
