#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int tujuan;
    int jarak;
};

// Nama kota
string namaKota[6] = {
    "Medan",    //misal ini A(0)
    "Tebing Tinggi",  //ini B(1)
    "Brastagi",       //ini C(2)
    "Pematangsiantar", //ini D(3)
    "Sidikalang",  //ini E(4)
    "Parapat"  //ini F(5)
};

// Graf tidak berarah berbobot
vector<Edge> graf[6] = {  //0=A, 1=B, 2=C, 3=D, 4=E, 5=F
    {{1, 70}, {2, 60}}, // A->B(70 Km), A->C(60 Km)
    {{3, 50}},        // B -> D(50 Km)
    {{4, 90}, {3, 80}}, // C -> E(90 Km), C->D(80 Km)
    {{5, 45}, {4, 65}}, // D -> F(45 Km), D->E(65 Km)
    {{5, 120}}, // E -> F(120 Km)
};

void BFS(int start, int goal) {
    queue<vector<int>> q; 
    bool visited[6] = {false}; 
    q.push({start}); 
    visited[start] = true; 

    while (!q.empty()) { 
        vector<int> path = q.front(); 
        q.pop();

        int kotaSekarang = path.back(); 

        if (kotaSekarang == goal) { 
            int totalJarak = 0;

            for (int i = 0; i < path.size(); i++) {
                int k = path[i];
                //kota terakhir tidak pakai " -> "
                if (i == path.size() - 1) {
                    cout << namaKota[k] << char(k) << endl;
                    break;
                }
                cout << namaKota[k] << char(k) << " -> ";
                if (i < path.size() - 1) { 
                    int next = path[i + 1]; 
                    for (int j = 0; j < graf[k].size(); j++) { 
                        if (graf[k][j].tujuan == next) { 
                            totalJarak += graf[k][j].jarak;
                            break;
                        }
                    }
                }
            }
            cout << "Total jarak: " << totalJarak << " Km";
            return;
        }
        
        for (int i = 0; i < graf[kotaSekarang].size(); i++) {
            int next = graf[kotaSekarang][i].tujuan;
            if (!visited[next]) { 
                visited[next] = true; 
                vector<int> newPath = path; 
                newPath.push_back(next); 
                q.push(newPath);
            }
        }
    }
}

int main() {
    system("cls");
    string asal,tujuan;
    int asalfiks, tujuanfiks;

    cout << "Kota yang tersedia: Medan, Tebing Tinggi, Brastagi, Pematangsiantar, Sidikalang, Parapat\n";
    cout << "Masukkan Vertex Asal: ";
    cin >> asal;
    cout << "Masukkan Vertex Tujuan: ";
    cin >> tujuan;

    if (asal == "Medan") asalfiks = 0;
    else if (asal == "Tebing Tinggi") asalfiks = 1;
    else if (asal == "Brastagi") asalfiks = 2;
    else if (asal == "Pematangsiantar") asalfiks = 3;
    else if (asal == "Sidikalang") asalfiks = 4;
    else if (asal == "Parapat") asalfiks = 5;
    else {
        cout << "Kota asal tidak valid.\n";
        return 0;
    }

    if (tujuan == "Medan") tujuanfiks = 0;
    else if (tujuan == "Tebing Tinggi") tujuanfiks = 1;
    else if (tujuan == "Brastagi") tujuanfiks = 2;
    else if (tujuan == "Pematangsiantar") tujuanfiks = 3;
    else if (tujuan == "Sidikalang") tujuanfiks = 4;
    else if (tujuan == "Parapat") tujuanfiks = 5;
    else {
        cout << "Kota tujuan tidak valid.\n";
        return 0;
    }

    BFS(asalfiks, tujuanfiks);
    return 0;
}
