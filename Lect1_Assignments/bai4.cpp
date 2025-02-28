#include <iostream> 
#include <vector>
using namespace std; 


void sortFunction (vector<int>arr){
	int n = arr.size();
	for (int i =0; i<n-1; i++){
		for (int j = i+1; j<n; j++){
			if (arr[i]> arr[j]) swap(arr[i], arr[j]);
		}
	}
	for (int i =0 ;i<arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout <<endl;
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i =0; i<n; i++){
		cin >> arr[i];
	}
	sortFunction(arr);

}
