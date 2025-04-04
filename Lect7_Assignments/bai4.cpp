#include <iostream>
#include <string> 
using namespace std;
// dùng đệ quy để tạo ra các dãy 0,1 với độ dài là n 
void generateBinaryRecursive(string prefix, int n) {
    if (n == 0) { 
        cout << prefix << endl; 
        return; 
    }
    generateBinaryRecursive(prefix + "0", n - 1); 
    generateBinaryRecursive(prefix + "1", n - 1);
}

int main() {
    int n;
    cin >> n;
    generateBinaryRecursive("", n);
    system("pause");
}
