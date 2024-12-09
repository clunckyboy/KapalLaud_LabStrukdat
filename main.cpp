#include <conio.h>
#include "inisialisasi.h"
using namespace std;

int main(){

   
   inisialisasiHash();

   while (true) {

      int opsi;

      system("cls");
      cout << "=============================================================================" << endl;
      cout << "                                 TOKO ONLINE                                 " << endl;
      cout << "=============================================================================" << endl;
      cout << "0. Keluar                                                                    " << endl;
      cout << "1. Sortir Produk Berdasarkan Kategori dan Harga (Sorting & Hash)             " << endl;
      cout << "2. Menambahkan Produk ke Keranjang Belanja (Array)                           " << endl;
      cout << "3. Mencari Produk Berdasarkan ID (Search & Hash)                             " << endl;
      cout << "4. Melihat Daftar Barang di Keranjang (Array)                                " << endl;
      cout << "5. Menghapus Barang dari Keranjang (Array)                                   " << endl;
      cout << "6. Menghitung Biaya Pengiriman Berdasarkan Jarak (Graph - Shortest Path)     " << endl; 
      cout << "7. Melakukan Pembayaran dan Menyimpan Riwayat Pembayaran (Array)             " << endl;
      cout << "8. Melihat Riwayat Pembayaran (Array)                                        " << endl;
      cout << "9. Melihat Detail Setiap Transaksi pada Riwayat Pembayaran (Array & Hash)    " << endl;
      cout << "=============================================================================" << endl;
      cout << "Pilih opsi (0-9) : "; cin >> opsi; 

      switch(opsi) {
         case 0 :
            cout << "Sampai berjumpa\n";
            return 0;

         case 1 : 
            system("cls");
            sortirProduk();
            cin.ignore();
            getch();
            break;

         case 2 : 
            system("cls");
            int tambahId;
            for (const auto& produk : daftarProduk) {
               cout << produk.id << " - " << produk.nama << " - " << produk.kategori << " - " << fixed << setprecision(0) << produk.harga << endl;
            }
            cout << "Masukkan ID produk yang ingin ditambahkan : ";
            cin >> tambahId;
            tambahKeranjang(tambahId);
            cin.ignore();
            getch();
            break;

         case 3 : 
            system("cls");
            int idKey;
            cout << "Masukkan ID : ";
            cin >> idKey;
            cariProduk(idKey);
            cin.ignore();
            getch();
            break;

         case 4 :
            system("cls");
            isiKeranjang();
            cin.ignore();
            getch();
            break;

         case 5 : 
            system("cls");
            int idHapus;
            cout << "Masukkan ID produk yang ingin dihapus : ";
            cin >> idHapus;
            hapusProduk(idHapus);
            cin.ignore();
            getch();
            break;

         case 6 : 
            system("cls");
            int titik;
            cout << "Masukkan titik pengiriman (1-9) : ";
            cin >> titik;
            
            if (titik <1 || titik >9) {
               cout << "titik " << titik << " tidak ada";
               getch();
               break;
            }

            hitungbiayaPengiriman(titik);
            cin.ignore();
            getch();
            break;

         case 7 : 
            system("cls");
            pembayaran();
            cin.ignore();
            getch();
            break;

         case 8 : 
            system("cls");
            lihatriwayatPembayaran();
            cin.ignore();
            getch();
            break;

         case 9 : 
            system("cls");
            int idTransaksi;
            for (const auto& i  : riwayatPembayaran) {
               cout << "ID Transaksi : " << i.idTransaksi << " || Rp " << fixed << setprecision(0) << i.totalHarga << endl;   
            }
            cout << "Masukkan ID Transaksi yang ingin dilihat : ";
            cin >> idTransaksi;
            lihatdetailTransaksi(idTransaksi);
            cin.ignore();
            getch();
            break;
         default : 
            break;   
      }  
   }
}