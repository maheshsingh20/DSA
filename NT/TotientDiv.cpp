/*Euler's Totient number*/

#include <bits/stdc++.h>
using namespace std;

vector<int> computeTotients(int N) {
    vector<int> phi(N + 1);
    for (int i = 0; i <= N; ++i)
        phi[i] = i;

    for (int i = 2; i <= N; ++i) {
        if (phi[i] == i) {
            for (int j = i; j <= N; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }

    return phi;
}

int main() {
    int N = 20;
    vector<int> phi = computeTotients(N);
    for (int i = 1; i <= N; ++i) {
        cout << "phi(" << i << ") = " << phi[i] << endl;
    }
    return 0;
}
