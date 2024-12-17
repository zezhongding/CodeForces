#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    int t;
    cin >> t;
    while (t--) {
        ll m, a, b, c;
        cin >> m >> a >> b >> c;
        ll ans = 0, va = 0;
        if (a < m) {
            ans += a;
            va += m - a;
        } else {
            ans += m;
        }
        if (b < m) {
            ans += b;
            va += m - b;
        } else {
            ans += m;
        }
        ans += min(va, c);
        cout << ans << endl;
    }
}