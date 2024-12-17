#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll quickpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}
ll quickfind(ll l1, ll r1, ll xx, ll val) {
    ll l = l1, r = r1;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (mid * val >= xx) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        ll ans = 0;
        for (int i = 0; i <= 32; ++i) {
            ll val = quickpow(k, i);
            if (val > 1e9) {
                break;
            }
            if (l1 * val > r2 || r1 * val < l2) {
                continue;
            }
            ll num1 = quickfind(l1, r1, l2, val);
            ll num2 = quickfind(l1, r1, r2, val);
            //core
            if (num1 * val < l2) num1++;
            if (num2 * val > r2) num2--;
            ans += max(0ll, num2 - num1 + 1);
        }
        cout << ans << endl;
    }
}