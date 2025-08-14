#include <iostream>
#include <string>
#include <limits>
using namespace std;
/*
Undo feature for a basic text editor Implemented with a custom stack (dynamic 
array) to store typed words.
*/
class UndoStack {
private:
    static const int CAPACITY = 100000;   // Max words allowed
    string* data;                         // Dynamic array for storing words
    int top;                               // Index of the last stored word
public:
    // Constructor: allocate memory for stack
    UndoStack() {
        data = new string[CAPACITY];
        top = -1;
    }
    // Destructor: free allocated memory
    ~UndoStack() {
        delete[] data;
    }
    // Add a word to the stack
    void push(const string& word) {
        if (top >= CAPACITY - 1) {
            cout << "[Error] Cannot add more words, stack is full.\n";
            return;
        }
        data[++top] = word;
    }
    // Remove the last word (Undo action)
    void pop() {
        if (top < 0) {
            cout << "[Info] Nothing to undo.\n";
            return;
        }
        cout << "[Undo] Removed \"" << data[top] << "\"\n";
        top--;
    }
    // Show all currently typed words
    void print() const {
        if (top < 0) {
            cout << "(empty)\n";
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
};
int main() {
    UndoStack editor;
    int choice;
    string word;
    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Type a Word\n";
        cout << "2. Undo Last Word\n";
        cout << "3. Show Current Text\n";
        cout << "4. Exit\n";
        cout << "Select: ";
        cin >> choice;
        // Handle non-integer input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[Error] Invalid input. Please enter a number.\n";
            continue;
        }
        switch (choice) {
            case 1:
                cout << "Enter word: ";
                cin >> word;
                editor.push(word);
                break;
            case 2:
                editor.pop();
                break;
            case 3:
                editor.print();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "[Error] Invalid choice.\n";
        }
    }
}
