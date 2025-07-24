#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a = 8;
  int b = 7;

  /*  swap two numbers
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  cout << a <<" "<< b << endl;
  */

  /*  check if a number is even or odd
  if((b & 1) == 0){
    cout << "even" << endl;
  }else{
    cout << "Odd" << "\n";
  }
  */

  /*  check if a number is power of 2*/

  /* convert binary number into integer

  auto number = 0b11011;
  cout << number<<endl;

  */
  /*Leading zero
   int number = 000340500010;
   cout << __builtin_clz(number) << endl;
   */

  /* Trailing zero
 long long int num = 13543000000;
 cout<<__builtin_ctz(num)<<endl;


  */

  /*  convert number into binary then it count number of 1 exist in its binary representation

  int num = 27;
  cout<<__builtin_popcount(num)<<endl;

  */
  /* Manual way of counting number of set bits
  int count = 0;
  for(int i = 0; i < 32; i++){
    if((b & (1 << i))){
      count++;
    }
  }
  cout<<count<<endl;

  */

  /* Check if ith bit is set or not
  int num = 12;
  cout<<((num & (1 << 4))==1)<<endl;
  */
 
  return 0;
}
