#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

void printTree(const vector<int>& heap) {
    int levels = log(heap.size())/log(2) + 1;
    int index = 0;
	int width = pow(2, levels) * 2;
   for (int i = 0; i < levels; i++) {
        int nodes = pow(2, i);
        int space = width / (nodes + 1);
        for (int j = 0; j < nodes && index < heap.size(); j++) {
            cout << setw(space) << heap[index++] << setw(space) << " ";
        }
        cout << endl;
    }
}
// đổi heap thành vector để in ra màn hình 
vector<int> convertHeapVector (priority_queue<int> maxHeap) {
	vector<int>heapVector;
	while (!maxHeap.empty()) {
        heapVector.push_back(maxHeap.top());
        maxHeap.pop();
    }
	return heapVector;
}


int main() {
	int arr[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]));

    priority_queue<int> maxHeap;

    // thêm phần tử vào heap trống
    for (int num : nums) {
        maxHeap.push(num);
    }
	// in ra heap tree sau khi mới thêm phần tử 
	vector<int> printVector= convertHeapVector(maxHeap);
	cout << "Heap Tree sau khi them cac phan tu : " <<endl;
	printTree(printVector);
	
	// tạo các phần tử 
	int del[] = {6,13,35};
	vector<int> toDelete(del, del+sizeof(del) /sizeof(del[0]));
    
	// Thêm node mới vào heap 
	int add[] = {14, 0, 35};
    vector<int> newNodes (add, add + sizeof(arr) / sizeof(arr[0]));
    for (int num : newNodes) {
        maxHeap.push(num);
    }
	// in ra màn hình Heap tree sau khi thêm 3 phần tử 
    vector<int> addVector= convertHeapVector(maxHeap);
	cout << "Heap Tree sau khi them 3 phan tu : " <<endl;
    printTree(addVector);


    // Xoá node trong heap tree 
	int remv[] = {6,13,15};
    vector<int> removeNodes(remv, remv + sizeof(arr) / sizeof(arr[0]));;
    vector<int> tempHeap;
    while (!maxHeap.empty()) {
        int top = maxHeap.top();
        maxHeap.pop();
        if (find(removeNodes.begin(), removeNodes.end(), top) == removeNodes.end()) {
            tempHeap.push_back(top);
        }
    }
    
    // tạo lại heap sau khi xoá 
    for (int num : tempHeap) {
        maxHeap.push(num);
    }

    vector<int> delVector= convertHeapVector(maxHeap);
   cout << "Heap Tree sau khi xoa cac phan tu " <<endl;
    printTree(delVector);


	system("pause");
}
