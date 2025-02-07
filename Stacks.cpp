/*

#include <iostream>
using namespace std;

class Stack {
public:
    int top1;
    int top2;
    int* arr;
    int size;

    // Constructor to initialize stack size and top positions
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Function to push data into the first stack
    void push1(int data) {
        if (top2 - top1 == 1) {
            cout << "Stack 1 Overflow" << endl;
        } else {
            top1++;
            arr[top1] = data;
        }
    }

    // Function to push data into the second stack
    void push2(int data) {
        if (top2 - top1 == 1) {
            cout << "Stack 2 Overflow" << endl;
        } else {
            top2--;
            arr[top2] = data;
        }
    }

    // Function to pop data from the first stack
    void pop1() {
        if (top1 == -1) {
            cout << "Stack 1 Underflow" << endl;
        } else {
            arr[top1]=0;
            top1--;
        }
    }

    // Function to pop data from the second stack
    void pop2() {
        if (top2 == size) {
            cout << "Stack 2 Underflow" << endl;
        } else {
            arr[top2]=0;
            top2++;
        }
    }

    // Function to print stack contents
    void print() {
        cout << endl;
        cout << "Top1: " << top1 << endl;
        cout << "Top2: " << top2 << endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s(9);

    // Testing push operations
    s.push1(10);
    s.print();
    s.push1(20);
    s.print();
    s.push1(30);
    s.print();
    s.push1(40);
    s.print();
    s.push1(50);
    s.print();

    s.push2(100);
    s.print();
    s.push2(90);
    s.print();
    s.push2(80);
    s.print();
    s.push2(70);
    s.print();

    // Testing pop operations
    s.pop2();
    s.print();

    // Testing overflow conditions
    s.push1(60);  // Should be successful
    s.print();
    s.push2(60);  // Should cause overflow
    s.print();

    // Testing underflow conditions
    for (int i = 0; i < 6; i++) {
        s.pop1();  // Pop all elements from Stack 1
    }
    s.print();

    s.pop1();  // Should cause underflow
    s.print();

    return 0;
}


*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/*Infix to Suffix*/

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return -1;
}

string INFIX_POSTFIX(string s)
{
    stack<char> st; // stack for operators
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '1' && s[i] <= '9'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push('(');
        }
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

/*Infix to Prefix */

string INFIX_PREFIX(string s)
{
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
            s[i] = '(';
        else if (s[i] == '(')
            s[i] = ')';
    }
    stack<char> st;

    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '1' && s[i] <= '9'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push('(');
        }
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(s[i]) < precedence(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

/*Prefix to infix*/

string PREFIX_INFIX(string s)
{
    string ans = "";
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '1' && s[i] <= '9'))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = "(" + op1 + s[i] + op2 + ")";
            st.push(temp);
        }
    }
    ans += st.top();
    return ans;
}

/*Postfix to Infix*/
string POSTFIX_INFIX(string s)
{
    string ans = "";
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '1' && s[i] <= '9'))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = "(" + op2 + s[i] + op1 + ")";
            st.push(temp);
        }
    }
    ans += st.top();
    return ans;
}

/*Prefix to postFix*/
string PREFIX_POSTFIX(string s)
{
    stack<string> st;
    string ans = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '1' && s[i] <= '9'))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = op1 + op2 + s[i];
            st.push(temp);
        }
    }
    ans += st.top();
    return ans;
}

/*post fix to prefix */
string POSTFIX_PREFIX(string s)
{
    stack<string> st;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '1' && s[i] <= '9'))
        {
            st.push(string(1, s[i]));
        }

        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = s[i] + op2 + op1;
            st.push(temp);
        }
    }
    ans += st.top();
    return ans;
}

int main()
{
    cout << INFIX_POSTFIX("(3-2+l/8)-(4+6/3*(5^8))") << endl;
    cout << INFIX_PREFIX("(3-2+l/8)-(4+6/3*(5^8))") << endl;
    cout << PREFIX_INFIX("-+-32/l8+4*/63^58") << endl;
    cout << POSTFIX_INFIX("32-l8/+463/58^*+-") << endl;
    cout << PREFIX_POSTFIX("-+-32/l8+4*/63^58") << endl;
    cout << POSTFIX_PREFIX("32-l8/+463/58^*+-") << endl;
}