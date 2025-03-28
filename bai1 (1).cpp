#include <iostream> 

using namespace std;
class Node{
public:
	int data;
	Node *left;
	Node*right;
	Node(int val): data(val), left(nullptr) , right(nullptr) {} // Hàm constructor khởi tạo 1 node trong tree
	
};
	Node* insertNode(Node *node , int val) {
		// nếu node trống thì tạo node mới rồi cho vào tree
		if (node == nullptr) {
			return new Node(val);
		} 
		
		//chèn node vào bên trái hoặc phải nếu có chỗ trống bằng cách dùng đệ quy 
		if (val < node-> data){
			node -> left = insertNode(node->left, val);  // nhỏ hơn thì chèn vào node bên trái 
		}else if (val > node-> data){
			node -> right = insertNode(node->right, val); // lớn hơn thì chèn vào node bên phải 
		}

		// trả về vị trí root của cây sau khi đc tạo ra khi đã chèn xong giá trị 
		return node;

	}

Node* findMin(Node* root) { // hàm tìm node nhỏ nhất (trường hợp node cần xoá là node có con) 
    while (root->left != nullptr){
        root = root->left;
	}
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (!root) return root; // nếu không có giá trị thì không cần xoá 
    if (val < root->data) root->left = deleteNode(root->left, val);  // nếu giá trị cần xoá nhỏ hơn node đang trỏ vào-> di chuyển sang trái 
    else if (val > root->data) root->right = deleteNode(root->right, val);  // nếu giá trị cần xoá lớn hơn node đang trỏ vào-> di chuyển sang phải 
    else { // tìm được node cần xoá 
        if (!root->left) { // nếu node cần xoá ko có con ở bên trái 
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) { // nếu node cần xoá ko có con ở bên phải hoặc ko có node con 
            Node* temp = root->left;
            delete root;
            return temp;
        }
		// nếu node cần xoá có 2 con : 
        Node* temp = findMin(root->right); // chọn node bé nhất có trong cây con bên phải để thay thế -> không làm mất cấu trúc của BST  
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}



void printTree(Node* root, int level = 0) { // in cây trên màn hình dạng nằm ngang ( root gần lề nhất , right ở trên root và left ở dưới root )
    if (root) {
        printTree(root->right, level + 1);  // in phần bên phải của cây
        for (int i = 0; i < level; i++){ // tạo cách lề để biểu diễn các node 
			cout << "    ";
		}
        cout << " -> " << root->data << endl;  // lệnh in ra các node 
        printTree(root->left, level + 1);   // in phần bên trái của cây 
    }
}


int main(){
	int arr[9] = {2,1,10,6,3,8,7,13,20};
	int add[3]={14,0,35};
	int del[3] = {6,13,35};
	Node *root = nullptr;
	for (int i = 0; i<9; i++){
		root = insertNode(root,arr[i]);
	}
	cout << "Cay nhi phan ban dau: "<<endl;
	printTree(root);
	 for (int i = 0; i<3; i++){
		root = insertNode(root,add[i]);
	}
	cout << "Cay nhi phan sau khi them phan tu:  "<<endl;
	printTree(root);
	for (int i = 0; i<3; i++){
		root = deleteNode(root,del[i]);
	}
	cout << "Cay nhi phan sau khi xoa phan tu: " <<endl;
	printTree(root);
	system("pause");
}