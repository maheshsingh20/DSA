// Author: Mahesh_SINGH
// Date: 2025-06-20
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <immintrin.h>  // AVX/SSE intrinsics

using namespace std;
using namespace __gnu_pbds;

// Aliases
#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ef emplace_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define ub upper_bound
#define lb lower_bound
#define ff first
#define ss second
#define endl '\n'

// Debug
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", _debug(__VA_ARGS__)
#else
#define debug(...) 
#endif

// Constants
const int MOD = 1e9 + 7;
const int MOD1 = 998244353;
const int INF = 1e18;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

// Fast IO
inline namespace FastIO {
    const int BSZ = 1<<15;
    char ibuf[BSZ]; int ipos, ilen;
    char obuf[BSZ]; int opos;
    
    void init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ipos = ilen = 0;
        opos = 0;
    }

    char rc() {
        if (ipos == ilen) {
            ipos = 0;
            ilen = (int)fread(ibuf, 1, BSZ, stdin);
            if (!ilen) return EOF;
        }
        return ibuf[ipos++];
    }

    void flush() {
        fwrite(obuf, 1, opos, stdout);
        opos = 0;
    }

    void wc(char c) {
        if (opos == BSZ) flush();
        obuf[opos++] = c;
    }
}

// Utility Functions
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using max_heap = priority_queue<T>;
template<typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using omultiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Hashing
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename T1, typename T2>
    size_t operator()(pair<T1, T2> const& p) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(p.first + FIXED_RANDOM) ^ splitmix64(p.second + FIXED_RANDOM);
    }
};
template<typename K, typename V> using hash_map = gp_hash_table<K, V, custom_hash>;
template<typename T> using hash_set = gp_hash_table<T, null_type, custom_hash>;

// Math Functions
template<typename T> T binpow(T a, T b, T m = MOD) {
    a %= m; T res = 1; while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m; b >>= 1;
    } return res;
}
int gcd(int a, int b) { while (b) a %= b, swap(a, b); return a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int modinv(int a, int m = MOD) { return binpow(a, m - 2, m); }
int ceil_div(int a, int b) { return (a + b - 1) / b; }

// Combinatorics
const int N = 2e5 + 5;
vector<int> fact(N), invFact(N), inv(N);
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i-1] * i % MOD;
    invFact[N-1] = modinv(fact[N-1]);
    for (int i = N-2; i >= 0; i--) invFact[i] = invFact[i+1] * (i+1) % MOD;
    inv[1] = 1;
    for (int i = 2; i < N; i++) inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;
}
int nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
int nPr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invFact[n - r] % MOD;
}

// Data Structures
struct DSU {
    vector<int> parent, size, min_elem, max_elem;
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        min_elem.resize(n);
        max_elem.resize(n);
        iota(all(parent), 0);
        iota(all(min_elem), 0);
        iota(all(max_elem), 0);
    }
    int find(int v) { return v == parent[v] ? v : parent[v] = find(parent[v]); }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        min_elem[a] = min(min_elem[a], min_elem[b]);
        max_elem[a] = max(max_elem[a], max_elem[b]);
        return true;
    }
};

template<typename T>
struct Fenwick {
    int n;
    vector<T> tree;
    Fenwick(int _n) : n(_n), tree(_n + 1) {}
    void update(int idx, T delta) {
        for (; idx <= n; idx += idx & -idx) tree[idx] += delta;
    }
    T query(int idx) {
        T res = 0;
        for (; idx > 0; idx -= idx & -idx) res += tree[idx];
        return res;
    }
    T range_query(int l, int r) { return query(r) - query(l - 1); }
};

template<typename T>
struct SegmentTree {
    int n;
    vector<T> tree;
    function<T(T, T)> combine;
    T neutral;
    SegmentTree(int _n, function<T(T, T)> _combine, T _neutral) 
        : n(_n), tree(2 * _n, _neutral), combine(_combine), neutral(_neutral) {}
    void update(int idx, T val) {
        for (tree[idx += n] = val; idx > 1; idx >>= 1)
            tree[idx >> 1] = combine(tree[idx], tree[idx ^ 1]);
    }
    T query(int l, int r) {
        T res = neutral;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res = combine(res, tree[l++]);
            if (~r & 1) res = combine(res, tree[r--]);
        }
        return res;
    }
};

// String Algorithms
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

// Graph Algorithms
vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
    int n = adj.size();
    vector<int> dist(n, INF);
    min_heap<pair<int, int>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Debug Print
void _debug() { cerr << endl; }
template<typename T, typename... Args>
void _debug(T first, Args... rest) {
    cerr << first << " ";
    _debug(rest...);
}

// Main
void solve() {
    // Your solution here
    _debug(nCr(8, 3));
}

signed main() {
    FastIO::init();
    precompute();
    int t = 1;
    cin >> t;
    while (t--) solve();
    FastIO::flush();
    return 0;
}