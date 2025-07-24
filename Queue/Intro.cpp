#include <iostream>
using namespace std;
/* Implementation of queue using array
class Queue{
  public:
    int front;
    int back;
    int capacity;
    int *arr;
    Queue(int n){
      arr = new int[n];
      front = 0;
      back = -1;
      capacity = n;
    }

    void push(int num){
      if(capacity-1==back){
        cout << "Queue is full" << endl;
      }
      back++;
      arr[back] = num;
    }
    void pop(){
      if(front>back){
        cout << "Queue is empty" << endl;
        return;
      }
      front++;
    }
    int getFront(){
      if(back-front+1<=0){
        return -1;
      }
      return arr[front];
    }
    int getSize(){
      return (back!=-1)?back-front+1:0;
    }
    int getBack(){
      if(back-front+1<=0){
        return -1;
      }
      return arr[back];
    }
    void print(){
      for (int i = front; i <= back;i++){
        cout << arr[i] << " ";
      }
      cout << endl;
    }
};
int main(){
  Queue qt(5);
  qt.push(1);
  qt.push(2);
  qt.push(3);
  cout << qt.getSize() << endl;
  qt.print();
  qt.pop();
  qt.print();
  cout << qt.getFront()<<endl;
  cout << qt.getBack() <<endl;
  qt.push(4);
  qt.push(5);
  qt.print();
  qt.push(6);
  return 0;
}
*
