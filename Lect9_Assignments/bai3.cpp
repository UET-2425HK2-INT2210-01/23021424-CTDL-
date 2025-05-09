#include <iostream>
#include <vector>
using namespace std; 

int maxNum(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	int n,m;
	cin >> n >>m;
	vector<int> weight(n), value(n);
	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> value[i];
	}
	vector<int> dp(m + 1, 0);
	
	// thuật toán 0/1 Knapsack 
	for (int i = 0; i < n; i++) {
		for (int w = m; w >= weight[i]; w--) {
			dp[w] = maxNum(dp[w], dp[w - weight[i]] + value[i]);
		}
	}
	cout << dp[m] << endl;
}