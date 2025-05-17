// #include <bits/stdc++.h>
// using namespace std;


/*
typedef stack<int> s;
typedef stack<char> c;
void printStack(auto &st){
    while(!st.empty()){
        cout<< st.top()<<" ";
        st.pop();
    }
}

/*
  -->> Notes about stack
  1. Stack follow last in First out (LIFO)
  2. Stack is data structure we can use to reverse things (list of Data)
  3. 


int main(){
    s st;
    int size=10;
    for(int i=10;i>=1;i--){
        st.push(i);
    }
    c ct;
    for(char ch='a';ch<='z';ch++){
        ct.push(ch);
    }
    printStack(ct);
    return 0;
}

*/


#include <iostream>
using namespace std;

class Stack {
public:
    int size;
    int top;
    int *arr;

    Stack(int size) {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data) {
        if (top < size - 1) {
            top++;
            arr[top] = data;
        } else {
            cout << "Stack is Overflowed!" << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is Underflow!" << endl;
        } else {
            top--;
        }
    }

    int GetTop() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        } else {
            return arr[top];
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    int getSize() {
        return top + 1;
    }
};

void print(Stack st) {
    while (!st.isEmpty()) {
        cout << st.GetTop() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st.push(6);  // Overflow case
    print(st);
    st.pop();
    print(st);
    return 0;
}
