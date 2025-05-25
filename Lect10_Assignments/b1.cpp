#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100005;

vector<int> adj[MAX]; // Danh sách kề
bool visited[MAX];
int n, m;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int main() {
    cin >> n >> m;

    // Nhập các cạnh
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Vì đồ thị vô hướng
    }

    int components = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    cout << components << endl;
    return 0;
}
