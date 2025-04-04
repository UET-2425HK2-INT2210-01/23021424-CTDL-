#include <iostream>
#include <vector>
#include <string> 
using namespace std;
// dùng đệ quy để tính các hoán vị từ 1-> n
void generatePermutations(vector<int>& nums, vector<bool>& used, string current, int n) {
	// nếu chuỗi có độ dài bằng n thì kết thúc đệ quy và in ra hoán vị 
    if (current.length() == n) {  
		cout << current << endl;
        return;
    }
    // lặp để in ra các hoán vị 
    for (int i = 0; i < n; i++) {
		// nếu giá trị used chưa đc sử dụng (used[i] = false) 
        if (!used[i]) {
            used[i] = true; // đã được sử dụng -> chỉnh về true 
            generatePermutations(nums, used, current + std::to_string(nums[i]), n); //gọi hàm đệ quy để tạo 1 hoán vị 
            used[i] = false; // sau khi hoán vị xong thì biến sẽ ko còn được sử dụng nữa nên chỉnh về false để dùng cho lần tạo hoán vị tiếp theo 
        }
    }
}

int main() {
    int n;
	cin >> n;
	// tạo 1 mảng gòm các giá trị từ 1-> n
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }
	// tạo 1 mảng để đánh dấu xem biến đã được sử dụng chưa (mặc định chưa sử dụng là false)
    vector<bool> used(n, false);

    
	// gọi hàm đệ quy để in ra các hoán vị 
    generatePermutations(nums, used, "", n);
    system("pause");
}
