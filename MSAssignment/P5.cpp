#include <iostream>
#include <string>
using namespace std;
bool isValidUsername(string userName) {
    int len = userName.length();
    /* first check the length */
    if (len < 5 || len > 20) return false;
    /* check first chrter to be letter */
    if (!((userName[0] >= 'A' && userName[0] <= 'Z') || (userName[0] >= 'a' && userName[0] <= 'z')))
        return false;
   /* check all chrcters to be letter or digit */
    for (int i = 0; i < len; i++) {
        if (!((userName[i] >= 'A' && userName[i] <= 'Z') ||
              (userName[i] >= 'a' && userName[i] <= 'z') ||
              (userName[i] >= '0' && userName[i] <= '9'))) {
            return false;
        }
    }
    return true;
}
int main() {
    string username;
    cin >> username;
    if (isValidUsername(username))
        cout << "Valid Username" << endl;
    else
        cout << "Invalid Username" << endl;
    return 0;
}
