#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        k--;
        vector<ll> ans(n);
        if (n <= 50) {
            if (k >= (1LL << n - 1)) {
                cout << -1 << endl;
                continue;
            }
        }
        int left = 0, right = n - 1;
        ll hp = n - 2;
        ll cur = 1;
        while(hp >= 0) {
            if (hp <= 50 && k >= (1LL << hp)) {
                ans[right--] = cur++;
                k -= (1LL << hp);
            }
            else {
                ans[left++] = cur++;
            }
            hp--;
        }
        while (cur <= n) {
            ans[left++] = cur++;
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}