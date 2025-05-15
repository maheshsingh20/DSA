#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    string st="12 14 133 13 12";
    istringstream iss(st);
    for(int i=0;i<5;i++){
        int x;
        iss>>x;
        cout<<x*3 <<endl;
    }
}