// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// class node {
// public:
//     int data;
//     node* left;
//     node* right;
//     node(int data) {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// // Build tree function
// node* buildTree() {
//     int data;
//     cout << "Enter data: ";
//     cin >> data;
//     if (data == -1) {
//         return NULL;
//     }
//     node* newNode = new node(data);
//     cout << "Enter data for the left of " << data << ": " << endl;
//     newNode->left = buildTree();
//     cout << "Enter data for the right of " << data << ": " << endl;
//     newNode->right = buildTree();
//     return newNode;
// }

// // Level order traversal function
// void levelOrderTraversal(node* root) {
//     if (root == NULL) {
//         return;
//     }
//     queue<node*> q;
//     q.push(root);
//     q.push(NULL);

//     while (!q.empty()) {
//         node* temp = q.front();
//         q.pop();

//         if (temp == NULL) {
//             cout << endl;  // End of current level
//             if (!q.empty()) {
//                 q.push(NULL);  // Insert NULL to mark the end of the next level
//             }
//         } else {
//             cout << temp->data << " ";
//             if (temp->left) {
//                 q.push(temp->left);
//             }
//             if (temp->right) {
//                 q.push(temp->right);
//             }
//         }
//     }
// }

// // Helper function for calculating diameter
// int helperofDiameter(node* root, int &diam) {
//     if (root == NULL) {
//         return 0;
//     }

//     int leftt = helperofDiameter(root->left, diam);
//     int rightt = helperofDiameter(root->right, diam);

//     // Update the diameter if the current path is larger
//     diam = max(diam, leftt + rightt);

//     // Return the height of the current node
//     return max(leftt, rightt) + 1;
// }

// // Function to calculate diameter
// int diameter(node* root) {
//     int diam = 0;
//     helperofDiameter(root, diam);
//     return diam;
// }

// // Helper function to find elements at the k-th level
// void KthLevelHelperFunction(node* root, int k, vector<int> &result) {
//     if (root == NULL || k < 0) {
//         return;
//     }

//     if (k == 0) {
//         result.push_back(root->data);
//         return;
//     }

//     KthLevelHelperFunction(root->left, k - 1, result);
//     KthLevelHelperFunction(root->right, k - 1, result);
// }

// // Function to get the elements at the k-th level
// vector<int> KthLevel(node* root, int k) {
//     vector<int> result;
//     KthLevelHelperFunction(root, k, result);
//     return result;
// }


// int LCA(node* root){

// }

// int main() {
//     node* root = buildTree();   // Build the tree
//     cout << "Level order traversal of the tree:" << endl;
//     levelOrderTraversal(root);  // Perform level-order traversal

//     // Print the diameter of the tree
//     cout << "Diameter of tree is: " << diameter(root) << endl;

//     // Print the elements at the 3rd level
//     vector<int> kthLevelNodes = KthLevel(root, 3);
//     cout << "Elements at the 3rd level of the tree: ";
//     for (int val : kthLevelNodes) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Function to delete a node in BST
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        Node* temp = root->right;
        while (temp->left) temp = temp->left;
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val, height;
    Node *left, *right;
    Node(int v) : val(v), height(1), left(nullptr), right(nullptr) {}
};

int getHeight(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

void updateHeight(Node* n) {
    if (n)
        n->height = 1 + max(getHeight(n->left), getHeight(n->right));
}

// Right rotate
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);
    return x;
}

// Left rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);
    return y;
}

// Rebalance the tree at node
Node* rebalance(Node* node) {
    updateHeight(node);
    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    // Left Right
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    // Right Left
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Get min value node
Node* getMin(Node* node) {
    while (node->left) node = node->left;
    return node;
}

// Delete in AVL tree
Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        } else {
            Node* temp = getMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return rebalance(root);
}

// Inorder print
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(50);
    root = deleteNode(root, 50); // initially one node

    root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    root = deleteNode(root, 50); // delete root

    inorder(root);
    return 0;
}


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* btrec(){
    int data;
    cout << "Enter data (-1 for no node): ";
    cin >> data;
    
    if(data == -1){
        return NULL;
    }
    
    node* root = new node(data);
    
    cout << "Enter data for left of " << data << ": ";
    root->left = btrec();
    
    cout << "Enter data for right of " << data << ": ";
    root->right = btrec();
    
    return root;
}

void levelordertraversal(node* root){
    if(root == NULL) return;

    queue<node*> q;
    q.push(root);
    q.push(NULL); // Marker for new level
    
    while (!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL); // Add marker for next level
            }
        }else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

bool solveforLCA(node* root, int n, vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n) return true;
    int leftt=solveforLCA(root->left,n,path);
    int rightt=solveforLCA(root->right,n,path);
    if(leftt||rightt){
        return true;
    }
    path.pop_back();
    return false;
}

vector<int> pathofnode(node* root, int k){
    vector<int> path;
    solveforLCA(root, k,path);
    return path;
}

int LCA(node* root, int k, int j) {
    if (root == nullptr) return 0;
    if (root->data == k || root->data == j) return root->data;

    int leftt = LCA(root->left, k, j);
    int rightt = LCA(root->right, k, j);

    if (leftt && rightt) return root->data;
    else if (leftt) return leftt;
    else return rightt;
}


int lowestCommonAncestor(node* root, int k ,int j){
    vector<int> path1;
    vector<int> path2;

    solveforLCA(root ,k,path1);
    solveforLCA(root ,j,path2);
    int LCA=0;
    for(int i=0,j=0;i<path1.size() && j<path2.size();i++,j++){
        if(path1[i]!=path2[j]){
            break;
        }else{
            LCA=path1[i];
        }
    }
    return LCA;
}
 
int kthAncestor(node* root, int k, int node){
    if(root==NULL){
        return -1;
    }
    if(root->data==node) return 0;
    int l=kthAncestor(root->left,k,node);
    int r=kthAncestor(root->right,k,node);
    if(l==-1 && r==-1){
        return -1;
    }
    int validd=l==-1?r:l;
    int anss=0;
    if(validd+1==k){
        anss=root->data;
    }
    return anss;
}



int mininum(node* root){
    if(root==NULL) return INT_MAX;
    int leftt=mininum(root->left);
    return leftt;
}


node* deleteNode(node* root, int key){
    if(root==NULL) return root;
    if(root->data==key){
        //if 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //if 1 child
        if(root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        if(root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        //if 2 child
        int mini=mininum(root->right);
        root->data=mini;
        root->right=deleteNode(root->right,mini);
        return root;
    }
    root->left=deleteNode(root->left,key);
    root->right=deleteNode(root->right,key);
    return root;
}




int main(){
    node* root = btrec();
    cout << "Level Order Traversal:" << endl;
    levelordertraversal(root);
    // int res=lowestCommonAncestor(root, 8, 7);
    // cout << "Lowest Common Ancestor: " << res << endl;
    // cout<<"Path of node is: ";
    // vector<int> path = pathofnode(root, 6);
    // for (int i = 0; i < path.size(); i++) {
    //     cout << path[i] << " ";
    // }
    // cout << endl;
    // cout<<"Lowest Common Ancestor: "<<LCA(root,8,7)<<endl;


    cout<<"Kth from Node: "<<kthAncestor(root,8,3)<<endl;
    return 0;
}
