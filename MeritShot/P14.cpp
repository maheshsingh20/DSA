#include <iostream>
#include <string>
using namespace std;
/*
Binary Tree Node for storing employee names. Each node has: name (employee's \
name)  pointer to left child pointer to right child
*/
struct EmployeeNode {
    string name;
    EmployeeNode* left;
    EmployeeNode* right;
    EmployeeNode(const string& empName) {
        name = empName;
        left = nullptr;
        right = nullptr;
    }
};
/*
Class to manage the Employee Hierarchy (Binary Tree)
*/
class EmployeeTree {
private:
    EmployeeNode* root;
    // Recursive helper for inorder traversal
    void inorder(EmployeeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);          // Visit left subtree
        cout << node->name << " ";    // Visit root
        inorder(node->right);         // Visit right subtree
    }
public:
    EmployeeTree() {
        root = nullptr;
    }
    // Insert employee into the tree (simple BST logic for example purposes)
    EmployeeNode* insert(EmployeeNode* node, const string& empName) {
        if (node == nullptr) {
            return new EmployeeNode(empName);
        }
        if (empName < node->name) {
            node->left = insert(node->left, empName);
        } else {
            node->right = insert(node->right, empName);
        }
        return node;
    }
    void addEmployee(const string& empName) {
        root = insert(root, empName);
    }
    // Public method to print employees in inorder
    void printInorder() {
        if (root == nullptr) {
            cout << "(No employees in the hierarchy)\n";
            return;
        }
        cout << "Inorder Employee List: ";
        inorder(root);
        cout << "\n";
    }
};
// Main program
int main() {
    EmployeeTree company;
    int n;
    string name;
    cout << "Enter number of employees: ";
    cin >> n;
    // Clear newline left by integer input
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Enter employee name: ";
        getline(cin, name);
        company.addEmployee(name);
    }
    company.printInorder();
    return 0;
}
