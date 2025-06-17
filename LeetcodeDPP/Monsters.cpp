#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Compare {
    bool operator()(pair<ll, ll>& a, pair<ll, ll>& b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for (ll& x : arr) cin >> x;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> pq;
        for (ll i = 0; i < n; i++) {
            arr[i]=arr[i]%k;
            if (arr[i] == 0)
                arr[i]= k;
            pq.push({arr[i], i+1});
        }
        while(!pq.empty()){
            cout<< pq.top().second << " ";
            pq.pop();
        }
        cout << "\n";
    }
    return 0;
}