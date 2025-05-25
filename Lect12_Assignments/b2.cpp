#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc lưu thông tin một cạnh: từ đỉnh u đến đỉnh v với trọng số d
struct Edge {
    int u, v, d;
};

// Mảng cha dùng cho thuật toán Union-Find
int parent[10005];

// Hàm tìm gốc của một đỉnh (có path compression)
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);  // nén đường đi
    return parent[x];
}

// Hàm hợp nhất hai tập hợp chứa x và y
void unite(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    ifstream fin("connection.txt");     // Đọc dữ liệu đầu vào từ file
    ofstream fout("connection.out");    // Ghi kết quả đầu ra vào file

    int n, m;  // n là số máy tính, m là số kết nối
    fin >> n >> m;

    vector<Edge> edges;

    // Đọc m dòng, mỗi dòng là một cạnh giữa u và v với trọng số d
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        fin >> u >> v >> d;
        edges.push_back({ u, v, d });
    }

    // Sắp xếp tất cả các cạnh theo trọng số tăng dần (thuật toán Kruskal yêu cầu)
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.d < b.d;
        });

    // Khởi tạo cấu trúc Union-Find (mỗi đỉnh là cha của chính nó)
    for (int i = 1; i <= n; ++i) parent[i] = i;

    int totalCost = 0;           // Tổng chi phí kết nối
    vector<Edge> mst;            // Danh sách cạnh trong cây khung nhỏ nhất

    // Duyệt từng cạnh theo thứ tự trọng số tăng dần
    for (const Edge& e : edges) {
        // Nếu u và v thuộc 2 tập khác nhau, thêm cạnh này vào cây khung
        if (find(e.u) != find(e.v)) {
            unite(e.u, e.v);     // Hợp nhất hai tập
            totalCost += e.d;    // Cộng chi phí
            mst.push_back(e);    // Lưu cạnh này vào cây khung
        }
    }

    // Ghi kết quả ra file: dòng đầu là tổng chi phí
    fout << totalCost << endl;
    // Các dòng tiếp theo là các cạnh trong cây khung
    for (const Edge& e : mst) {
        fout << e.u << " " << e.v << " " << e.d << endl;
    }

    return 0;
}
