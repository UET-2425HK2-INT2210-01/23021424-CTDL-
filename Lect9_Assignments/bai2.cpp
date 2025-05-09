#include <iostream>
#include <vector>
using namespace std; 
bool findSum(vector<int>& arr, int index, int target, vector<int>& subset) {
	if (target == 0) return true; // đệ quy dừng khi đã tìm được tổng 
	if (index >= arr.size() || target < 0) return false; // đệ quy dừng khi đã duyệt tất cả mảng và không tìm được các bộ số có tổng = X 

	//tính tổng bắt đầu từ arr[index]
	subset.push_back(arr[index]);
	if (findSum(arr, index + 1, target - arr[index], subset)) return true;

	// tính tổng tiếp theo và bỏ qua arr[index]
	subset.pop_back();
	return findSum(arr, index + 1, target, subset);
}

int main() {
	int n,x;
	cin >> n >>x;
	vector<int>arr(n); 
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> subset;
	if (findSum(arr, 0, x, subset)) cout << "YES" << endl;
	else cout << "NO" << endl;

}