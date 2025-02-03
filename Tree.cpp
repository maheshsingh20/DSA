#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Constructing a binary tree from user input
Node* buildTree() {
    int d;
    cin >> d;
    if (d == -1) {
        return NULL;
    }
    Node* root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// Level Order Traversal
void printTree(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (curr == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

// Inorder Traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Height of Tree
int height(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Diameter of Tree (Optimized)
pair<int, int> diameterHelper(Node* root) {
    if (!root) return {0, 0}; // {diameter, height}
    auto left = diameterHelper(root->left);
    auto right = diameterHelper(root->right);
    int dia = max(left.first, max(right.first, left.second + right.second + 1));
    return {dia, max(left.second, right.second) + 1};
}

int diameter(Node* root) {
    return diameterHelper(root).first;
}

// Width of Tree
int width(Node* root) {
    if (root == NULL) return 0;
    queue<Node*> q;
    q.push(root);
    int ans = 0;
    while (!q.empty()) {
        int size = q.size();
        ans = max(ans, size);
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return ans;
}



int main() {
    Node* root = buildTree();
    
    cout << "Level Order Traversal:\n";
    printTree(root);
    
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
    
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;
    
    cout << "Height of Tree: " << height(root) << endl;
    cout << "Diameter of Tree: " << diameter(root) << endl;
    cout << "Width of Tree: " << width(root) << endl;
    
    return 0;
}
