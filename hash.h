// Fungsi untuk melihat detail transaksi
void lihatdetailTransaksi(int id) {
   system("cls");
    for (const auto &pembayaran : riwayatPembayaran) {
        if (pembayaran.idTransaksi == id) {
            int i = 1;
            cout << "Detail Transaksi ID " << pembayaran.idTransaksi << ":\n";
            for (const auto &produk : pembayaran.keranjang) {
                cout << i << ". " << produk.nama << " - " << produk.kategori << " - Rp " << fixed << setprecision(0) << produk.harga << endl;
                i++;
            }
            cout << "Total harga : Rp " << fixed << setprecision(0) << pembayaran.totalHarga;
            return;
        }
    }
    cout << "Transaksi tidak ditemukan!\n";
}