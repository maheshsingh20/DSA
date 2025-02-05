#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

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

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == NULL) {
        return true;
    }
    if (root->data <= minVal || root->data >= maxVal) {
        return false;
    }
    return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
}

bool ifBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}


bool isSearchable(Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (root->data < key) {
        return isSearchable(root->right, key);
    }
    return isSearchable(root->left, key);
}

void LOT(Node* root){
	if(root == NULL){
		return;
	}
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
	    Node* temp = q.front();
	    q.pop();
	    if(temp == NULL){
	        if(!q.empty()){
	            q.push(NULL);
				cout<<endl;
	        }
	    } else {
	        cout << temp->data << " ";
	        if(temp->left != NULL){
	            q.push(temp->left);
	        }
	        if(temp->right != NULL){
	            q.push(temp->right);
	        }
	    }
	}

}






int main() {
    Node* root = buildTree();
    // if (ifBST(root)) {
    //     cout << "Yes, it is a BST" << endl;
    // } else {
    //     cout << "No, it is not a BST" << endl;
    // }



	// if (isSearchable(root, 13)){
	// 	cout << "Yes, it is searchable" << endl;
	// }else{
	// 	cout << "No, it is not searchable" << endl;
	// }


    LOT(root);
	return 0;
}
