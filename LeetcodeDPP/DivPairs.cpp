#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int size, x, y;
        cin >> size >> x >> y;
        vector<int> arr(size);
        for(int i = 0; i < size; i++){
            cin >> arr[i];
        }
        int count = 0;
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                int sum = arr[i] + arr[j];
                int diff = arr[i] - arr[j];
                if(abs(sum) % x == 0 && abs(diff) % y == 0){
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
