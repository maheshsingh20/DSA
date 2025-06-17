#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        vector<int> firstMins, secondMins;
        for (int i = 0; i < n; i++) {
            int size;
            cin >> size;
            arr[i].resize(size);
            for (int j = 0; j < size; j++) {
                cin >> arr[i][j];
            }
            sort(arr[i].begin(), arr[i].end());
            firstMins.push_back(arr[i][0]);
            secondMins.push_back(arr[i][1]);
        }
        int minSecond = *min_element(secondMins.begin(), secondMins.end());
        int smallestFirst = *min_element(firstMins.begin(), firstMins.end());
        int minIndex = min_element(secondMins.begin(), secondMins.end()) - secondMins.begin();
        secondMins[minIndex] = smallestFirst;
        long long beauty = 0;
        for (int x : secondMins) beauty += x;

        cout << beauty << '\n';
    }
    return 0;
}
