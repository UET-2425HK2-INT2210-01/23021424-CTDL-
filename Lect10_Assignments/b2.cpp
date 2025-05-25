#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// khai báo ngoài hàm main để tránh việc queue overflow khi MAX quá lớn 
const int MAX = 100005;

vector<int> adj[MAX];
bool visited[MAX];
int distanceFromX[MAX];


int main() {
   
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // lưu các cặp giá trị mảng vector , key là giá trị đầu còn value là giá trị cuối 
    }

    // bắt đầu duyệt từ X 
    queue<int> q;
    q.push(X);
    visited[X] = true;
    distanceFromX[X] = 0;

    while (!q.empty()) {
        int u = q.front(); // lấy giá trị đầu tiên từ queue gán = u 
        q.pop();  //lấy giá trị ra khỏi queue bằng lệnh pop

        // duyệt hết mảng nếu tìm thấy đc cặp có dạng adj[i] = k và adj[k] = n với n,k,i là các số 

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                distanceFromX[v] = distanceFromX[u] + 1;
                q.push(v);
            }
        }
    }

    if (visited[Y]) {
        cout << distanceFromX[Y] << endl; // in ra đường ngắn nhất từ X đến Y 
    }
    else {
        cout << -1 << endl; // không có đường đi từ X đến Y
    }

    return 0;
}
