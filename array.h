// tambahkan produk ke keranjang
void tambahKeranjang(int id) {    
    if (hashProduk.find(id) != hashProduk.end()) {
        keranjang.push_back(hashProduk[id]);
        string namaProduk = hashProduk[id].nama; 
        cout << namaProduk << " berhasil ditambahkan!\n";
    } else {
        cout << "Produk tidak ditemukan!\n";
    }
}

//lihat isi keranjang
void isiKeranjang() {
    double total = 0;
    if (keranjang.empty()) {
        cout << "Keranjang kosong!\n";
        return;
    }
    for (const auto &i : keranjang) {
        cout << i.id << ". " << i.nama << " || " << i.kategori << " || Rp " << fixed << setprecision(0) << i.harga << endl;
        total += i.harga;
    }
    cout << "Total harga : Rp " << fixed << setprecision(0) << total;
}

//hapus produk dari keranjang
void hapusProduk(int id) {
    auto i = find_if(keranjang.begin(), keranjang.end(), [id](const Produk &produk) { return produk.id == id; });
    if (i != keranjang.end()) {
        cout << i->nama << " berhasil dihapus!\n";
        keranjang.erase(i);
    } else {
        cout << "Produk tidak ditemukan di keranjang!\n";
    }
}

//melakukan pembayaran
void pembayaran() {
    if (keranjang.empty()) {
        cout << "Keranjang kosong! Tidak perlu membayar\n";
        return;
    }

    int i=1;
    double total = 0;
    for (const auto &produk : keranjang) {
        cout << i << ". " << produk.nama << " - " << produk.kategori << " - Rp " << fixed << setprecision(0) << produk.harga << endl;
        total += produk.harga;
        i++;
    }
    riwayatPembayaran.push_back({idTransaksiawal++, keranjang, total});
    keranjang.clear();
    cout << "Pembayaran berhasil!\nTotal: Rp " << fixed << setprecision(0) << total << endl;
}

//lihat riwayat pembayaran
void lihatriwayatPembayaran() {
    if (riwayatPembayaran.empty()) {
        cout << "Riwayat pembayaran kosong!\n";
        return;
    }
    for (const auto &pembayaran : riwayatPembayaran) {
        cout << "ID Transaksi: " << pembayaran.idTransaksi << " - Total: Rp " << fixed << setprecision(0) << pembayaran.totalHarga << endl;
    }
}