#include <iostream> 

using namespace std; 




int main(){
	int arr[5];
	for (int i = 0; i<5; i++){
		cin >> arr[i];
	}
	int max = arr[0], min =arr[0];
	for (int i=1; i<5; i++){
		if (arr[i] > max ) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}
	cout << max + min <<endl;
	
}
