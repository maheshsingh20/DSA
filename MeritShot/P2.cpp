#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            int temp = a[i];
            a[i] = a[maxIdx];
            a[maxIdx] = temp;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
/* Intuition 
Think of it like a teacher arranging students from highest marks to lowest:
first, find the top scorer in the class and put them at position 1.
next, find the second-highest scorer from the remaining students and put them at position 2.
keep doing this until all students are arranged in descending order.  
It's more like take first  element of list mark it as greatest now comprae with each if
we find greater than that we update greater element and after checking in first iteration if
i is not equal to maxidx we swap that we repeat this process for all elements with remaining elements 
each pass places the next highest mark in the correct spot, so after i passes, the first i+1 elements 
are sorted correctly in descending order.
*/