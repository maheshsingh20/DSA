#include <iostream>
using namespace std;

void reverseArr(int a[], int l, int r) {  
    while (l < r) { // loop until left index is less than right index
        // swap elements at left and right index
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
      // move indices towards the center
        l++;
        r--;
    }
}
/*
 function to reverse the array
*/
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n, k;// n number of element in array and k  is number postion it rotate
   cin >> n;
   cin >> k; // taking input of number of position to rotate
   int a[n];
   for (int i = 0; i < n; i++)
      cin >> a[i]; 
   k = k % n; // check case so that k always remain in range of n
   reverseArr(a, 0, k - 1);  // reverse first k elements
   reverseArr(a, k, n - 1); // reverse last n-k elements
   reverseArr(a, 0, n - 1); // reverse whole array 
   cout << "Array after rotation: ";
   for (int i = 0; i < n; i++)
      cout << a[i] << " ";
   cout << endl;
   return 0;
}
