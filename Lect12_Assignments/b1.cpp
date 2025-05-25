#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <unordered_map>
using namespace std;

int main() {
    ifstream fin("jobs.txt");
    ofstream fout("jobs.out");

    int n, m;
    fin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1, 0);
    unordered_map<int, int> firstAppear; // dùng để ưu tiên đỉnh xuất hiện sớm

    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
        if (firstAppear.find(u) == firstAppear.end()) firstAppear[u] = i;
        if (firstAppear.find(v) == firstAppear.end()) firstAppear[v] = i + 100000; // đảm bảo v sau u nếu v chưa xuất hiện trước
    }

    // custom comparator theo thứ tự xuất hiện đầu tiên
    auto cmp = [&](int a, int b) {
        return firstAppear[a] > firstAppear[b];
        };
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);

    for (int i = 1; i <= n; ++i)
        if (inDegree[i] == 0) q.push(i);

    vector<int> result;
    while (!q.empty()) {
        int u = q.top(); q.pop();
        result.push_back(u);
        for (int v : adj[u]) {
            if (--inDegree[v] == 0)
                q.push(v);
        }
    }

    for (int job : result)
        fout << job << " ";

    return 0;
}
