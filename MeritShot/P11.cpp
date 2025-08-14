#include <iostream>
using namespace std;
/*
Node structure for the singly linked list Each node stores songName =the name
 of the song next : pointer to the next song
*/
struct SongNode {
    string songName;
    SongNode* next;

    SongNode(string name) {
        songName = name;
        next = nullptr;
    }
};
/*
Playlist class Implements addSong = Add song at the end reverseList = Reverse
 the linked list in-place display = Show all songs in current order
*/
class Playlist {
private:
    SongNode* head;
public:
    Playlist() {
        head = nullptr;
    }
    // Add a song at the end
    void addSong(string name) {
        SongNode* newSong = new SongNode(name);
        if (head == nullptr) {
            head = newSong;
            return;
        }
        SongNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
    // Reverse the linked list in-place
    void reverseList() {
        SongNode* prev = nullptr;
        SongNode* current = head;
        SongNode* nextNode = nullptr;
        while (current != nullptr) {
            // Save the next node
            nextNode = current->next;
            // Reverse the link
            current->next = prev;
            // Move pointers forward
            prev = current;
            current = nextNode;
        }
        head = prev; // New head is the previous tail
    }
    // Display the playlist
    void display() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        SongNode* temp = head;
        while (temp != nullptr) {
            cout << temp->songName << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    Playlist playlist;
    int choice;
    string name;
    do {
        cout << "\nPlaylist Menu:\n";
        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Reverse Playlist\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                cin.ignore();
                getline(cin, name);
                playlist.addSong(name);
                break;
            case 2:
                playlist.display();
                break;
            case 3:
                playlist.reverseList();
                cout << "Playlist reversed.\n";
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
    return 0;
}
