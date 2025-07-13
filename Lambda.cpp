#include <iostream>
using namespace std;

int main() {

  auto sum = [&](int &a, int &b) -> int
  {
    a++;
    return a + b;
  };
  int a = 10;
  int b = 15;
  cout << sum(a,b) << endl; // 26
  cout << a << endl;
  return 0;
};
