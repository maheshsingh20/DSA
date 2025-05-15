#include <iostream>
#include <string>
using namespace std;


// size_t simpleHash(const std::string& str) {
//     size_t hash = 0;
//     for (char ch : str) {
//         hash = hash * 31 + static_cast<size_t>(ch); // 31 is a common prime multiplier
//     }
//     return hash;
// }

// int main() {
//     std::string input = "Hello, World!";
//     size_t hashValue = simpleHash(input);

//     std::cout << "Hash value: " << hashValue << std::endl;
//     return 0;
// }




int main(){
    string str = "Hello, World!";
    cout<<str<<endl;
    return 0;
}