#include <iostream>
using namespace std;
/*
Node structure for a doubly linked list Each coach stores,coachNumber:integer
representing coach ID,prev:pointer to previous coach, next:pointer to next coach
*/
struct CoachNode {
    int coachNumber;
    CoachNode* prev;
    CoachNode* next;
    CoachNode(int num) {
        coachNumber = num;
        prev = nullptr;
        next = nullptr;
    }
};
/*
Train Class
Implements doubly linked list for managing train coaches.
Supports:
1. Add coach at the front
2. Add coach at the end
3. Remove a coach from the middle (by coach number)
*/

class Train {
private:
    CoachNode* head;
    CoachNode* tail;
public:
    Train() {
        head = nullptr;
        tail = nullptr;
    }
    // Add coach at the front of the train
    void addFront(int coachNum) {
        CoachNode* newCoach = new CoachNode(coachNum);
        if (head == nullptr) { // Empty list
            head = tail = newCoach;
            return;
        }
        newCoach->next = head;
        head->prev = newCoach;
        head = newCoach;
    }
    // Add coach at the end of the train
    void addEnd(int coachNum) {
        CoachNode* newCoach = new CoachNode(coachNum);
        if (tail == nullptr) { // Empty list
            head = tail = newCoach;
            return;
        }
        tail->next = newCoach;
        newCoach->prev = tail;
        tail = newCoach;
    }
    // Remove a coach from the middle (by number)
    void removeCoach(int coachNum) {
        if (head == nullptr) {
            cout << "Train is empty. Cannot remove.\n";
            return;
        }
        CoachNode* current = head;
        while (current != nullptr && current->coachNumber != coachNum) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Coach not found: " << coachNum << "\n";
            return;
        }
        // Case 1: Removing head
        if (current == head) {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr; // List became empty
        }
        // Case 2: Removing tail
        else if (current == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        // Case 3: Removing from middle
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        cout << "Removed coach: " << coachNum << "\n";
    }
    // Display train from front to back
    void displayTrain() {
        if (head == nullptr) {
            cout << "Train is empty.\n";
            return;
        }
        cout << "Train coaches (front to back): ";
        CoachNode* temp = head;
        while (temp != nullptr) {
            cout << temp->coachNumber << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};
int main() {
    Train train;
    int choice, num;
    do {
        cout << "\nTrain Management Menu:\n";
        cout << "1. Add Coach at Front\n";
        cout << "2. Add Coach at End\n";
        cout << "3. Remove Coach by Number\n";
        cout << "4. Display Train\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter coach number: ";
                cin >> num;
                train.addFront(num);
                break;
            case 2:
                cout << "Enter coach number: ";
                cin >> num;
                train.addEnd(num);
                break;
            case 3:
                cout << "Enter coach number to remove: ";
                cin >> num;
                train.removeCoach(num);
                break;
            case 4:
                train.displayTrain();
                break;
            case 5:
                cout << "Exiting Train Management.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
    return 0;
}
