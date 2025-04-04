#include <iostream> 
using namespace std; 
// hàm dùng đệ quy để tính ucln 
// dùng thuật toán lấy a = b và b=a%b cho đến khi b == 0 thì a chính là ucln
int ucln (int a, int b){ 
	if (b == 0 ) return a;
	else return ucln(b,a%b);
}
int main() {
	int a,b;
	// nhập 2 số a b 
	cin >> a >> b;
	cout << ucln(a,b) <<endl;

}