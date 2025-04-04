#include <iostream> 
#include <vector> 
#include <fstream> 
using namespace std; 
int sumKadane(vector<int> &arr, int &start , int &end, int n){ // tính tổng theo 1 chiều của mảng 2 chiều 
	int max_sum = INT_MIN, sum = 0;
	start = 0 ; 
	end = -1;
	int temp_start = 0;
	 for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            temp_start = i + 1;
        } else if (sum > max_sum) {
            max_sum = sum;
            start = temp_start;
            end = i;
        }
    }

    // Nếu tất cả các phần tử đều âm, chọn phần tử lớn nhất
    if (end == -1) {
        max_sum = arr[0];
        start = end = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > max_sum) {
                max_sum = arr[i];
                start = end = i;
            }
        }
    }

    return max_sum;
}

// Hàm tìm hình chữ nhật con có tổng lớn nhất trong ma trận 2D
void findMaxSumRectang(const vector<vector<int>>& matrix,int &max_sum ,int &final_left, int &final_right, int &final_top, int &final_bottom) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    
	// Hàm tính tổng các cột r lưu thành 1 hàng 
    for (int left = 0; left < cols; left++) {
        vector<int> temp(rows, 0);
        for (int right = left; right < cols; right++) {
            for (int i = 0; i < rows; i++) {
                temp[i] += matrix[i][right];
            }

            int start, end;
            int sum = sumKadane(temp, start, end, rows); // sử dụng hàm sumKadane tạo ra ở trên để tính hàng gồm tổng của các cột 

            if (sum > max_sum) { // so sánh để tìm ra tổng lớn nhất 
                max_sum = sum;
                final_left = left+1;
                final_right = right+1;
                final_top = start+1;
                final_bottom = end+1;
            }
        }
    }
}
int main(){
	int n,m;
	ifstream fileopen("matrix.txt");
	int sum = INT_MIN;
	fileopen >> m >> n; 
	vector<vector<int>>arr(m, vector<int>(n));
	for (int i = 0; i<m ; i++){
		for (int j = 0; j<n; j++){
			fileopen >> arr[i][j];
		}
	}
	fileopen.close();
	int left,right,top,bottom;
	findMaxSumRectang(arr,sum,left,right,top,bottom);
	// left ,right là toạ độ cột còn top,bottom là toạ độ hàng 
	ofstream fileread("matrix_out.txt");
	fileread << top << " " << left <<" "<< bottom <<" " << right <<" "<< sum << endl;
	fileread.close();
	system("pause");
}