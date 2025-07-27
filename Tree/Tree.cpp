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
// Count Total Nodes
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
//  Count Leaf Nodes
int countLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

//  Mirror Tree
void mirror(Node* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

//  Check Identical Trees
bool isIdentical(Node* a, Node* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return (a->val == b->val &&
            isIdentical(a->left, b->left) &&
            isIdentical(a->right, b->right));
}

//  LCA in Binary Tree
Node* lca(Node* root, int n1, int n2) {
    if (!root) return nullptr;
    if (root->val == n1 || root->val == n2) return root;
    Node* l = lca(root->left, n1, n2);
    Node* r = lca(root->right, n1, n2);
    if (l && r) return root;
    return l ? l : r;
}

//  Validate BST
bool isBST(Node* root, Node* minN = nullptr, Node* maxN = nullptr) {
    if (!root) return true;
    if (minN && root->val <= minN->val) return false;
    if (maxN && root->val >= maxN->val) return false;
    return isBST(root->left, minN, root) && isBST(root->right, root, maxN);
}

//  Path from root to given node
bool pathToNode(Node* root, int target, vector<int>& path) {
    if (!root) return false;
    path.push_back(root->val);
    if (root->val == target) return true;
    if (pathToNode(root->left, target, path) || pathToNode(root->right, target, path))
        return true;
    path.pop_back();
    return false;
}

//  Zigzag Traversal
vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int n = q.size();
        vector<int> level(n);
        for (int i = 0; i < n; ++i) {
            Node* node = q.front(); q.pop();
            int index = leftToRight ? i : n - 1 - i;
            level[index] = node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        leftToRight = !leftToRight;
        res.push_back(level);
    }
    return res;
}

//  Max Path Sum
int maxPathSum(Node* root, int& maxSum) {
    if (!root) return 0;
    int l = max(0, maxPathSum(root->left, maxSum));
    int r = max(0, maxPathSum(root->right, maxSum));
    maxSum = max(maxSum, l + r + root->val);
    return root->val + max(l, r);
}

//  Check if Tree is Balanced
bool isBalanced(Node* root, int& height) {
    if (!root) {
        height = 0;
        return true;
    }
    int lh = 0, rh = 0;
    bool lb = isBalanced(root->left, lh);
    bool rb = isBalanced(root->right, rh);
    height = 1 + max(lh, rh);
    return lb && rb && abs(lh - rh) <= 1;
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
