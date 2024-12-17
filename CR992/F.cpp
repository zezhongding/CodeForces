#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3000010;
const int mod = 998244353;
int fact[N], ifact[N], phi[N];

int qpow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return qpow(x, mod - 2);
}

int prepare() {
    fact[0] = 1;
    for(int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % mod;
    ifact[N - 1] = inv(fact[N - 1]);
    for(int i = N - 2; i >= 0; i--) ifact[i] = ifact[i + 1] * (i + 1) % mod;
    phi[1] = 1;
    for (int i = 2; i < N; ++i) {
        phi[i] = i - 1;
    }
    for (int i = 2; i < N; ++i) {
        for (int j = i * 2; j < N; j += i) {
            phi[j] -= phi[i];
        }  
    }
}

int C(int n, int k) {
    if(n < k) return 0;
    return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

int MC(vector <int> &a) {
    int sum = 0;
    for (int i : a) sum += i;
    int res = fact[sum];
    for (int i : a) res = res * ifact[i] % mod;
    return res;
}

int lcm(int a, int b) {
    return a / __gcd(a, b) * b ;
}

vector <int> all_divs(int x) {
    vector <int> res;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (i * i != x) res.push_back(x / i);
        }
    }
    return res;
}

void solve() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    vector <int> v(k);
    for (int &i : v) cin >> i;
    int g = v[0];
    for (int i : v) g = __gcd(g, i);
    map <int, int> mp;
    for (int i : all_divs(a)) {
        for (int j : all_divs(b)) {
            for (int l : all_divs(c)) {
                int x = lcm(i, lcm(j, l));
                if (g % x == 0) {
                    mp[x] += phi[i] * phi[j] * phi[l];
                }
            }
        }
    }
    int sum = 0;
    for (auto pr : mp) {
        int N = pr.first;
        int cnt = pr.second;
        vector <int> u;
        for (int i : v) {
            u.push_back(i / N);
        }
        sum = (sum + (MC(u) * cnt) % mod) % mod;
    }
    sum = (sum * inv(a * b * c)) % mod;
    cout << sum << endl;
}


int32_t main () {
    prepare();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
