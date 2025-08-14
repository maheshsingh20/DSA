/* Question 1: Sales Report Analysis */
#include <iostream>
using namespace std;
void maxSale(int a[], int n) {
    int currMaxTillNow = a[0], dayOfMax = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > currMaxTillNow) { 
            currMaxTillNow = a[i];
            dayOfMax = i;
        }
    }
    cout << "Maximum Sale: " << currMaxTillNow << "\n";
    cout << "Day of Maximum Sale: " << dayOfMax + 1 << "\n";
}

/*Took two variable one for storing current maxsale till
current day and one for storing day of current max day
We iterate through the array and update these variables
whenever we find a new maximum sale. */

void minSale(int a[], int n) {
    int currMinTillNow = a[0], dayOfMin = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < currMinTillNow) {
            currMinTillNow = a[i];
            dayOfMin = i;
        }
    }
    cout << "Minimum Sale: " << currMinTillNow << "\n";
    cout << "Day of Minimum Sale: " << dayOfMin + 1 << "\n";
}
/*Took two variable one for storing currmin till now when we iterate and
one for storing day of that min sale , when we encounter 
lesser sale then curr we update currmin and day of min sale */
void averageSale(int a[], int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    cout << "Average Sale: " << (double)sum / n << "\n";
}
/*Took sum of all sales of each day and divide
 by number by day and findout avaerage*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;  // taking input number of days 
    int a[n];
    for (int i = 0; i < n; i++)//taking input of sales  of each day
        cin >> a[i];
    maxSale(a, n); // call for max sale 
    minSale(a, n); //call for min sale
    averageSale(a, n); // call for average sale
    return 0;
}
