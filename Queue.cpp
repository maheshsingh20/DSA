#include <iostream>
// #include <deque>
// #include <queue>
using namespace std;




// int main(){
//     queue<int> q;

//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.push(5);

//     cout<<"Front of Queue is: "<<q.front()<<endl;
//     cout<<"Size of Queue is: "<<q.size()<<endl;
//     cout<<"Back of Queue: "<<q.back()<<endl;
//     cout<<endl;

//     cout<<"Now About Deque"<<endl;

//     deque<int> d;
    
//     d.push_back(1);
//     d.push_back(2);
//     d.push_back(3);
//     d.push_back(4);
//     d.push_back(5);
//     d.push_back(6);
//     d.push_front(0);

//     cout<<endl;

//     cout<<"Front of Deque is: "<<d.front()<<endl;
//     cout<<"Size of Deque is: "<<d.size()<<endl;
//     cout<<"Back of Deque: "<<d.back()<<endl;

//     d.pop_front();
//     d.pop_back();

//     cout<<endl;

//     cout<<"Front of Deque is: "<<d.front()<<endl;
//     cout<<"Size of Deque is: "<<d.size()<<endl;
//     cout<<"Back of Deque: "<<d.back()<<endl;



    
//     return 0;
// }


//Self-Create function using Array

// #include <iostream>
// using namespace std;

// class Queue {
// public:
//     int *arr;
//     int front;
//     int back;
//     int capacity;

//     Queue(int c) {
//         arr = new int[c];
//         capacity = c;
//         front = 0;
//         back = -1;
//     }

//     ~Queue() {
//         delete[] arr;
//     }

//     void push(int x) {
//         if (back == capacity - 1) {
//             cout << "Queue is Full" << endl;
//             return;
//         }
//         back++;
//         arr[back] = x;
//     }

//     void pop() {
//         if (front > back) {
//             cout << "Queue is Empty" << endl;
//             return;
//         }
//         cout << arr[front] << " is removed from the queue" << endl;
//         front++;
//     }

//     int getFront() {
//         if (front > back) {
//             cout << "Queue is Empty" << endl;
//             return -1; // Return an invalid value
//         }
//         return arr[front];
//     }

//     int size() {
//         return (front > back) ? 0 : back - front + 1;
//     }

//     int getBack() {
//         if (front > back) {
//             cout << "Queue is Empty" << endl;
//             return -1; // Return an invalid value
//         }
//         return arr[back];
//     }

//     void print() {
//         if (front > back) {
//             cout << "Queue is Empty" << endl;
//             return;
//         }
//         for (int i = front; i <= back; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// };

// int main() {
//     Queue q(5);

//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.push(5);
//     q.print();
//     cout << endl;

//     cout << q.getFront() << endl;
//     cout << q.getBack() << endl;
//     cout << q.size() << endl;

//     q.pop();
//     q.print();
//     q.pop();
//     q.pop();
//     q.pop();
//     q.pop();
//     q.print();

//     return 0;
// }




//Circular Queue


#include <iostream>
using namespace std;

class Queue {
    
}