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







//   Front <<<-->>> Middle <<<-->>> Rear
#include <iostream>
using namespace std;

class FrontMiddleBackQueue {
public:
    int *arr;
    int front, rear, count, size;

    FrontMiddleBackQueue(int capacity = 11) {
        size = capacity;
        arr = new int[size];
        front = rear = -1;
        count = 0;
    }

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == size; }

    void pushFront(int val) {
        if (isFull()) return;
        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + size) % size;
        }
        arr[front] = val;
        count++;
    }

    void pushBack(int val) {
        if (isFull()) return;
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
        count++;
    }

    void pushMiddle(int val) {
        if (isFull()) return;
        int mid = (front + count / 2) % size;

        // Shift elements to right from rear to mid
        for (int i = rear; i != mid; i = (i - 1 + size) % size) {
            arr[(i + 1) % size] = arr[i];
        }

        arr[mid] = val;
        rear = (rear + 1) % size;
        count++;
    }

    int popFront() {
        if (isEmpty()) return -1;
        int val = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        count--;
        return val;
    }

    int popMiddle() {
        if (isEmpty()) return -1;
        int mid = (front + (count - 1) / 2) % size;
        int val = arr[mid];

        // Shift elements left from mid to rear
        for (int i = mid; i != rear; i = (i + 1) % size) {
            arr[i] = arr[(i + 1) % size];
        }

        rear = (rear - 1 + size) % size;
        count--;
        return val;
    }

    int popBack() {
        if (isEmpty()) return -1;
        int val = arr[rear];
        if (rear == front) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size;
        }
        count--;
        return val;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front, c = 0; c < count; i = (i + 1) % size, c++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    FrontMiddleBackQueue q;

    // Insert 1,2,3,4 from back
    q.pushBack(1);
    q.pushBack(2);
    q.pushBack(3);
    q.pushBack(4);
    q.pushBack(5);
    q.pushBack(6);
    q.pushBack(7);

    q.printQueue();
    cout<<"Front after pushBack operation: "<<q.front<<endl;
    cout<<"Rear after pushBack operation: "<<q.rear<<endl;
    cout<<"Size of queue: "<<q.size<<endl;

    
    // Insert 6,7,8,9,10 from front
   
    q.pushFront(8);
    q.pushFront(9);
    q.pushFront(10);

    q.printQueue();
    cout<<"Front after pushFront operation: "<<q.front<<endl;
    cout<<"Rear after pushFront operation: "<<q.rear<<endl;
    cout<<"Size of queue: "<<q.size<<endl;

    // Insert 5 in the middle
    q.pushMiddle(5);

    // Print queue state
    q.printQueue();

    // Pop operations
    cout << "Pop Back: " << q.popBack() << endl;
    cout << "Pop Front: " << q.popFront() << endl;
    cout << "Pop Middle: " << q.popMiddle() << endl;

    // Print final queue state
    q.printQueue();

    return 0;
}
