#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  vector<int> arr = {5, 6, 7, 8, 9, 1, 2, 3, 4};
  int n = arr.size();
  if (arr[n - 1] > arr[0])
  {
    cout << n - 1 << endl;
    return 0;
  }
  int low = 0, high = n - 1;
  while (low + 1 < high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
    {
      cout << mid << endl;
      return 0;
    }
    else if (arr[mid] >= arr[low])
    {
      low = mid;
    }
    else
    {
      high = mid;
    }
  }
  if (arr[low] > arr[high])
    cout << low << endl;
  else
    cout << high << endl;
  return 0;
}
