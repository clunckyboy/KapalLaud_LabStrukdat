// Fungsi untuk mencari shortest path menggunakan algoritma Dijkstra
void hitungbiayaPengiriman(int tujuan) {
    const int V = 10; // Jumlah titik dalam graf (0-9)
    const int INF = INT_MAX; // Angka tak terhingga untuk inisialisasi bobot
    
    // Matriks adjaceny untuk graf
    vector<vector<int>> graph(V, vector<int>(V, INF));
    
    // Menambahkan bobot untuk setiap pasangan titik
    graph[0][3] = 4;
    graph[0][6] = 4;
    graph[0][8] = 5;
    graph[0][2] = 7;
    graph[2][1] = 5;
    graph[6][1] = 4;
    graph[6][5] = 11;
    graph[6][4] = 2;
    graph[8][5] = 10;
    graph[4][7] = 7;
    graph[5][4] = 9;
    graph[5][7] = 8;
    graph[5][9] = 3;
    graph[9][7] = 4;

    // Inisialisasi jarak ke semua titik dengan nilai tak terhingga
    vector<int> dist(V, INF);
    dist[0] = 0; // Titik awal (titik 0)

    // Menyimpan apakah titik sudah dikunjungi
    vector<bool> visited(V, false);

    // Algoritma Dijkstra
    for (int i = 0; i < V - 1; ++i) {
        // Mencari titik dengan jarak terkecil yang belum dikunjungi
        int u = -1;
        for (int j = 0; j < V; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        // Tandai titik u sebagai sudah dikunjungi
        visited[u] = true;

        // Perbarui jarak ke tetangga u
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Mengalikan dengan 3000 sesuai permintaan
    cout << "Biaya pengiriman adalah : RP " << dist[tujuan] * 3000;
}