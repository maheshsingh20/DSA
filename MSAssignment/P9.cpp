#include <iostream>
#include <string>
using namespace std;
/* Node Structure: Represents a song in the playlist songName : stores the 
song title - next: pointer to the next node in the list */
struct SongNode {
    string songName;
    SongNode* next;
    SongNode(string name) {
        songName = name;
        next = nullptr;
    }
};
/* Playlist Class: Implements playlist as a singly linked list. Supports:
1. Add song at the end 2. Delete song by name 3. Display all songs */
class Playlist {
private:
    SongNode* head; // pointer to first song
public:
    Playlist() {
        head = nullptr;
    }
    // Add song at the end of the playlist
    void addSong(string name) {
        SongNode* newSong = new SongNode(name);
        if (head == nullptr) { // If playlist is empty
            head = newSong;
            return;
        }
        SongNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
    // Delete song by name
    void deleteSong(string name) {
        if (head == nullptr) {
            cout << "Playlist is empty. Cannot delete.\n";
            return;
        }
        // If song to delete is the first song
        if (head->songName == name) {
            SongNode* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted: " << name << "\n";
            return;
        }
        // Search for the song in the list
        SongNode* prev = nullptr;
        SongNode* curr = head;
        while (curr != nullptr && curr->songName != name) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "Song not found: " << name << "\n";
            return;
        }
        prev->next = curr->next;
        delete curr;
        cout << "Deleted: " << name << "\n";
    }
    // Display all songs in the playlist
    void displaySongs() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        SongNode* temp = head;
        cout << "Playlist:\n";
        while (temp != nullptr) {
            cout << "- " << temp->songName << "\n";
            temp = temp->next;
        }
    }
};
int main() {
    Playlist playlist;
    int choice;
    string name;
    do {
        cout << "\nPlaylist Menu:\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Songs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // ignore newline from previous input
        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                getline(cin, name);
                playlist.addSong(name);
                break;
            case 2:
                cout << "Enter song name to delete: ";
                getline(cin, name);
                playlist.deleteSong(name);
                break;
            case 3:
                playlist.displaySongs();
                break;
            case 4:
                cout << "Exiting playlist manager.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
    return 0;
}
