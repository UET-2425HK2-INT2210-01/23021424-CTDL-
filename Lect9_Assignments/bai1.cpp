#include <iostream>
#include <vector>
using namespace std;

// hàm chọn giá trị để đứng giữa (pivot) sau đó đưa các giá trị nhỏ hơn về trước còn lớn hơn thì ở đằng sau 
int partition(vector<int>&arr, int low, int high) {
	int pivot = arr[high]; // chọn pivot là vị trí cuối của mảng 
	int i = low;
	for (int j = low; j < high; j++) {
		// nếu giá trị trong mảng nhỏ hơn giá trị pivot chuyển về phía đầu của mảng 
		if (arr[j] < pivot) {
			swap(arr[i], arr[j]);
			i++;
		}
		
	}
	swap(arr[i], arr[high]); // đưa vị trí cuối về giữa mảng 
	return i;
}

//hàm đệ quy dùng QuickSort 
void quickSort(vector<int>&arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high); // chọn ra giá trị ở giữa 
		quickSort(arr, low, pi - 1); // sắp xếp tiếp mảng bên trái theo đệ quy tiếp tục chọn giá trị ở giữa cho đến khi chỉ có 1 giá trị duy nhất 
		quickSort(arr, pi + 1, high); // sắp xếp tiếp mảng bên phải theo đệ quy tiếp tục chọn giá trị ở giữa cho đến khi chỉ có 1 giá trị duy nhất 
	}
	// sau khi thực hiện đệ quy sẽ đc trả về mảng arr đã được sắp xếp 

}
int main() {
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}
	
