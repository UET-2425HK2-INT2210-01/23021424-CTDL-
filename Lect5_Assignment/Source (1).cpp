#include <iostream> 
#include <vector>
using namespace std;


class Node {
public:
    int val;                
    vector<Node*> children; 

    Node(int x) : val(x) {}
};


class Tree {
public:
    int N;
    vector<Node*> nodes;

    vector<int> parentOf;

    Node* root;

    Tree(int N) {
        this->N = N;
        nodes.resize(N+1, nullptr);
        parentOf.resize(N+1, 0); 
        root = nullptr;
        for (int i = 1; i <= N; i++) {
            nodes[i] = new Node(i);
        }
    }

    void addEdge(int u, int v) {
        nodes[u]->children.push_back(nodes[v]);
        parentOf[v] = u;
    }

    void findRoot() {
        for (int i = 1; i <= N; i++) {
            if (parentOf[i] == 0) {
                root = nodes[i];
                break;
            }
        }
    }
    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        if (node->children.empty()) {
            return 0;
        }
        int maxH = 0;
        for (auto child : node->children) {
            maxH = max(maxH, getHeight(child));
        }
        return maxH + 1;
    }

    void preorder(Node* node, vector<int>& res) {
        if (!node) return;
        res.push_back(node->val);
        for (auto child : node->children) {
            preorder(child, res);
        }
    }

    void postorder(Node* node, vector<int>& res) {
        if (!node) return;
        for (auto child : node->children) {
            postorder(child, res);
        }
        res.push_back(node->val);
    }

    bool isBinaryTree() {
        for (int i = 1; i <= N; i++) {
            if (nodes[i]->children.size() > 2) {
                return false;
            }
        }
        return true;
    }

    void inorder(Node* node, vector<int>& res) {
        if (!node) return;
        int sz = (int)node->children.size();
        if (sz == 2) {
            inorder(node->children[0], res); 
            res.push_back(node->val);       
            inorder(node->children[1], res); 
        }

        else if (sz == 1) {
            inorder(node->children[0], res); 
            res.push_back(node->val);       
        }
 
        else {
            res.push_back(node->val);
        }
    }
};


int main() {
   

    int N, M;
    cin >> N >> M;


    Tree tree(N);


    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }


    tree.findRoot();


    int height = tree.getHeight(tree.root);
    cout << height << "\n";


    vector<int> preRes;
    tree.preorder(tree.root, preRes);
    for (int i = 0; i < (int)preRes.size(); i++) {
        cout << preRes[i] << (i+1 < (int)preRes.size() ? " " : "\n");
    }


    vector<int> postRes;
    tree.postorder(tree.root, postRes);
    for (int i = 0; i < (int)postRes.size(); i++) {
        cout << postRes[i] << (i+1 < (int)postRes.size() ? " " : "\n");
    }


    if (tree.isBinaryTree()) {
        vector<int> inRes;
        tree.inorder(tree.root, inRes);
        for (int i = 0; i < (int)inRes.size(); i++) {
            cout << inRes[i] << (i+1 < (int)inRes.size() ? " " : "\n");
        }
    } else {
        cout << "NOT BINARY TREE\n";
    }

    system("pause");
}
