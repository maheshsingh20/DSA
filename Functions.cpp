#include <iostream>
#include <algorithm>
using namespace std;





int main(){
    string str = "Hello World";
    sort(str.begin(), str.end());
    cout<<str;
}