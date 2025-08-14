#include <iostream>
using namespace std;
/*
Circular Queue to manage parking spots Cars enter in FIFO order Cars leave in 
FIFO order Space wraps around when reaching the end of the array
*/
class ParkingQueue {
private:
    static const int MAX_SPOTS = 1000; // Maximum parking capacity
    int cars[MAX_SPOTS];               // Array to store car numbers
    int front;                          // Index of the first car
    int rear;                           // Index of the last car
    int count;                          // Number of cars currently parked
public:
    // Constructor: empty parking lot
    ParkingQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }
    // Add a car to the parking lot
    void enqueue(int carNumber) {
        if (count == MAX_SPOTS) {
            cout << "[Error] Parking lot full. Car " << carNumber << " cannot enter.\n";
            return;
        }
        rear = (rear + 1) % MAX_SPOTS;
        cars[rear] = carNumber;
        count++;
        cout << "Car " << carNumber << " parked.\n";
    }
    // Remove the first car in the lot
    void dequeue() {
        if (count == 0) {
            cout << "[Info] No cars in the parking lot.\n";
            return;
        }
        cout << "Car " << cars[front] << " left the parking lot.\n";
        front = (front + 1) % MAX_SPOTS;
        count--;
    }
    // Display all parked cars in order
    void display() const {
        if (count == 0) {
            cout << "(Parking lot is empty)\n";
            return;
        }
        cout << "Cars currently parked: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX_SPOTS;
            cout << cars[index] << " ";
        }
        cout << "\n";
    }
};
// Main function to demonstrate parking lot management
int main() {
    ParkingQueue lot;
    int choice, carNum;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Park a Car (Enqueue)\n";
        cout << "2. Car Leaves (Dequeue)\n";
        cout << "3. Show All Parked Cars\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter car number: ";
                cin >> carNum;
                lot.enqueue(carNum);
                break;
            case 2:
                lot.dequeue();
                break;
            case 3:
                lot.display();
                break;
            case 4:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "[Error] Invalid choice.\n";
        }
    }
}
