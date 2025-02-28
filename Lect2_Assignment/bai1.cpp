#include <iostream> 
#include <map>
#include <vector>
using namespace std; 
int main(){
	map<int, int> f;
	int n,dem = 0;
	cin >>n;
	vector<int>arr(n);
	for (int i =0; i<n; i++){
		cin >> arr[i];
		f[arr[i]]++;
	}
	for (const auto& k: f){
		dem+=k.second*(k.second-1)/2;
	}
	cout << dem <<endl;
	system("pause");
}