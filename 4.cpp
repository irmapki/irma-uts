#include <iostream>
using namespace std;

// deklarasi double linked list
struct DataUser {
  string nama, jurusan, NIM;
  DataUser *sebelumnya;
  DataUser *selanjutnya;
};

DataUser *kepala, *ekor, *saat_ini, *nodeBaru, *hapus, *setelahNode;

// Buat Double Linked List
void buatDoubleLinkedList(string data[3]) {
  kepala = new DataUser();
  kepala->nama = data[0];
  kepala->jurusan = data[1];
  kepala->NIM = data[2];
  kepala->sebelumnya = NULL;
  kepala->selanjutnya = NULL;
  ekor = kepala;
}

// Cetak Double Linked List
void cetakDoubleLinkedList() {
  if (kepala == NULL) {
    cout << "Double Linked List kosong" << endl;
  } else {
    saat_ini = kepala;
    while (saat_ini != NULL) {
      cout << "Nama: " << saat_ini->nama << ", Jurusan: " << saat_ini->jurusan << ", NIM: " << saat_ini->NIM << endl;
      saat_ini = saat_ini->selanjutnya;
    }
    cout << endl;
  }
}

// tambah Node Baru
void tambahNodeBaru(string data[3]) {
  nodeBaru = new DataUser();
  nodeBaru->nama = data[0];
  nodeBaru->jurusan = data[1];
  nodeBaru->NIM = data[2];
  nodeBaru->sebelumnya = NULL;
  nodeBaru->selanjutnya = NULL;

  if (kepala == NULL) {
    kepala = nodeBaru;
    ekor = nodeBaru;
  } else {
    ekor->selanjutnya = nodeBaru;
    nodeBaru->sebelumnya = ekor;
    ekor = nodeBaru;
  }
}

// hapus Awal
void hapusAwal() {
  if (kepala == NULL) {
    cout << "Double Linked List kosong" << endl;
  } else {
    hapus = kepala;
    kepala = kepala->selanjutnya;
    if (kepala != NULL)
      kepala->sebelumnya = NULL;
    delete hapus;
  }
}

// hapus Akhir
void hapusAkhir() {
  if (ekor == NULL) {
    cout << "Double Linked List kosong" << endl;
  } else {
    hapus = ekor;
    ekor = ekor->sebelumnya;
    if (ekor != NULL)
      ekor->selanjutnya = NULL;
    delete hapus;
  }
}

// hapus Tengah
void hapusTengah(int posisi) {
  if (kepala == NULL) {
    cout << "Double Linked List kosong" << endl;
  } else {
    if (posisi == 1) {
      hapusAwal();
    } else {
      saat_ini = kepala;
      int nomor = 1;
      while (saat_ini != NULL && nomor < posisi) {
        saat_ini = saat_ini->selanjutnya;
        nomor++;
      }
      if (saat_ini == NULL) {
        cout << "Posisi diluar jangkauan!!" << endl;
      } else {
        hapus = saat_ini;
        saat_ini->sebelumnya->selanjutnya = saat_ini->selanjutnya;
        if (saat_ini->selanjutnya != NULL)
          saat_ini->selanjutnya->sebelumnya = saat_ini->sebelumnya;
        delete hapus;
      }
    }
  }
}

int main() {
  string newData[3] = {"Irma ", "informatika", "1111"};
  buatDoubleLinkedList(newData);

  cetakDoubleLinkedList();

  newData[0] = "nur";
  newData[1] = "informatika"; 
  newData[2] = "2222";
  tambahNodeBaru(newData);
  cetakDoubleLinkedList();

  newData[0] = "megumi";
  newData[1] = "informatika"; 
  newData[2] = "3333";
  tambahNodeBaru(newData);
  cetakDoubleLinkedList();

  newData[0] = "ajimaste";
  newData[1] = "informatika"; 
  newData[2] = "4444";
  tambahNodeBaru(newData);
  cetakDoubleLinkedList();

  hapusTengah(2);
  cetakDoubleLinkedList();

  hapusAkhir();
  cetakDoubleLinkedList();

  hapusAwal();
  cetakDoubleLinkedList();

  return 0;
}