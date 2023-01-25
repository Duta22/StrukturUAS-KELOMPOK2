#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

const int MAX_ANTRIAN = 5;

struct orang {
    string nama;
    int umur;
    string alamat;
	int bb;
	int tb;
	string jenisk;
};

void buatAntrian(); // Mengisi antrian kosong sebanyak MAX_ANTRIAN dengan variabel kontrol
void tampilkanMenu(); // Menampilkan menu 
void eksekusiPilihan(); // mengambil pilihan dari user dan eksekusi pilihan tersebut
void invalid(); // jika angka yang dipilih tidak sesuai pada menu maka akan ada warning
void tambahAntrian(); // menambah antrian paling belakang
void kurangiAntrian(); // mengurangi antrian paling depan dan menampilkan orang yang keluar dari antrian
void printAntrian(); // menampilkan seluruh antrian yang ada


//inisisalisasi variabel yang akan dipakai
orang antrian[MAX_ANTRIAN];
int tes;

bool isEmpty = true;
bool isFull = false;
bool isOver = false;

//mengisi data awal dari antrian
void buatAntrian() {
    int i;
    for (i = 0; i < MAX_ANTRIAN; i++) {
        antrian[i].nama = "null"; // antrian dikatakan kosong apabila nama = null
        antrian[i].alamat = "null"; // antrian dikatakan kosong apabila alamat = null
        antrian[i].umur = -1; 				// dan umur = -1
        antrian[i].bb = -1; 				// dan berat badan = -1
        antrian[i].tb = -1;					 // dan tinggi badan = -1
        antrian[i].jenisk = "null";			 // antrian dikatakan kosong apabila jenis kelamin = null
    }
}

//Menampilkan Menu Utama
void tampilkanMenu() {
    system("cls");
    cout<<"<===============================================>"<<endl;
    cout<<"<         PROGRAM ANTRIAN VAKSIN COVID-19       >"<<endl;
    cout<<"<                    KELOMPOK 2                 >"<<endl;
    cout<<"<             RUMAH SAKIT PASAR REBO            >"<<endl;
    cout<<"<===============================================>"<<endl;
    cout << endl;

    cout << "(1) Tambah Antrian Vaksinasi Covid-19" << endl; 
    cout << "(2) Mengurangi Antrian Vaksinasi Covid-19" << endl; 
    cout << "(3) Cetak Antrian Vaksinasi Covid-19" << endl; 
    cout << "(4) Keluar Dari Program Vaksinasi Covid-19" << endl << endl; 
    cout << "Masukan Pilihan : "; 
    cin >> tes;
}

//pemrosesan pilihan dari menu utama 
void eksekusiPilihan() { 
    if (tes == 1) { 
        tambahAntrian(); 
    } 
    else if (tes == 2) { 
        kurangiAntrian(); 
    } 
    else if (tes == 3) {
        printAntrian();
    } 
    else if (tes == 4) { 
        isOver = true; 
    }
    else{
    	invalid();
	}
}

//prosedur jika angka yang dipilih tidak sesuai pada menu
void invalid(){
	cout << "Angka yang dimasukan tidak sesuai pada menu !" << endl;
	system ("pause");
}

//prosedur untuk penambahan data antrian 
void tambahAntrian() { 
    //diatur perulangan untuk memeriksa apakah ada antrian yang kosong 
    int i; 
        for (i=0; i<MAX_ANTRIAN; i++) { 
            //jika ada antrian yang kosong, maka data bisa dimasukkan 
            if(antrian[i].nama == "null" && antrian[i].umur == -1) {
                
                cout << "<=========  " << "Antrian Ke-" << i+1 << "  =========>" << endl; 
                cout << "Masukan Nama : "; 
                cin >> antrian[i].nama;
                cout << "Tempat Lahir : "; 
                cin >> antrian[i].alamat;
                cout << "Berat Badan : "; 
                cin >> antrian[i].bb;
                cout << "Tinggi Badan : "; 
                cin >> antrian[i].tb;
                cout << "Masukan Umur : "; 
                cin >> antrian[i].umur;
                cout << "Masukan Jenis Kelamin (Pria/Wanita): "; 
                cin >> antrian[i].jenisk;
                
                break; 
            } 
            //jika tidak ada yang kosong, maka tampilkan antrian penuh 
            else { 
                if (i == MAX_ANTRIAN-1) { 
                cout << "<=========  Antrian Telah Penuh  =========>" << endl; 
                } 
            } 
        } 
    system("pause"); 
}

//prosedur untuk mengurangi pengantri pertama, lalu antrian setelahnya maju. 
void kurangiAntrian() { 
    int i; 
    //tampilkan data yang akan dihapus 
    cout << "<=========  Antrian Ke-1 Telah Dihapus  =========>" << endl << endl; 
    cout << "Nama \t\t: " << antrian[0].nama << endl;
    cout << "Tempat Lahir \t: " << antrian[0].alamat << endl;
    cout << "Berat Badan \t: " << antrian[0].bb << " KG" << endl;
    cout << "Tinggi Badan \t: " << antrian[0].tb << " CM" << endl;
    cout << "Umur \t\t: " << antrian[0].umur << " Tahun" << endl;
    cout << "Jenis Kelamin \t: " << antrian[0].jenisk << endl<<endl; 
    
    //hapus data dengan mengisi "null" dan 1 
    antrian[0].nama = "null"; 
    antrian[0].umur = -1;

    //menggeser antrian ke atas 
    for(i=0; i<MAX_ANTRIAN-1; i++) { 
        antrian[i].nama = antrian[i+1].nama; 
        antrian[i].umur = antrian[i+1].umur; 
    } 
    
    //mengisi antrian terakhir dengan data kosong 
    antrian[MAX_ANTRIAN-1].nama = "null"; 
    antrian[MAX_ANTRIAN-1].umur = -1; 
    system("pause"); 
}

//prosedur menampilkan data semua antrian 
void printAntrian() { 
    int i; 
    for(i=0; i<MAX_ANTRIAN; i++) { 
        if(antrian[i].nama == "null" && antrian[i].umur == -1) { 
        	cout << "Antrian Ke-" << i+1 << " : Kosong";
            cout << endl;
        } 
        else { 
        	cout << "<=====Antrian ke-" << i+1<<"=====>" <<endl; 
            cout << "Nama \t\t: " << antrian[i].nama << endl;
			cout << "Tempat Lahir \t: " << antrian[i].alamat << endl;  
			cout << "Berat Badan \t: " << antrian[i].bb << " KG" << endl; 
			cout << "Tinggi Badan \t: " << antrian[i].tb << " CM" << endl; 
            cout << "Umur \t\t: " << antrian[i].umur << " Tahun" << endl;
			cout << "Jenis Kelamin \t: " << antrian[i].jenisk << endl; 
			cout << endl;
        } 
    } 
    system("pause"); 
}

int main() {
    buatAntrian();
    while(!isOver) {
        tampilkanMenu();
        eksekusiPilihan();
    }
    system("pause");
    return 0;
}

