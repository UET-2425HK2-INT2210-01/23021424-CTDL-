#include <iostream> 
#include <fstream> 
#include <vector> 
using namespace std;

int main(){
	int num;
	vector<int>arr;
	// đọc file numbers.txt 
	ifstream file("numbers.txt"); 
	// lấy các phần tử trong file và cho vào 1 mảng 
	while(file >> num){
		arr.push_back(num);  
	}
	int n = arr.size();
	// sắp xếp các phần tử trong mảng mới tạo 
	for (int i = 0; i<n-1; i++){
		for (int j = i+1; j<n; j++){
			if (arr[i]> arr[j]) swap(arr[i], arr[j]); 
		}
	}
	file.close();
	// tạo 1 file mới để lưu mảng sau khi sắp xếp 
	ofstream fileopen("numbers_sorted.txt");
	// ghi mảng đã sắp xếp vào file mới tạo
	for (int i = 0; i<n; i++){
		fileopen << arr[i] << " ";
	}
	fileopen.close();

}
