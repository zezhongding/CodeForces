#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    int t;
    cin >> t;
    while (t--) {
        ll n, q;
        cin >> n >> q;
        vector<vector<ll> > g(n);
        for (int i = 0; i < n - 1; i++) {
            ll u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ll m = n / 2 + 2;
        vector<vector<ll> > dp(n ,vector<ll>(m, 0));
        vector<int> fa(n);
        vector<int> layer(n);
        function<void(ll, ll)> dfs = [&](ll v, ll p = -1) {
            fa[v] = p;
            layer[v] = (p == -1 ? 0 : layer[p] + 1);
            for (ll u : g[v]) {
                if (u == p) continue;
                if (v == 0) {
                    dp[u][0] = 2 * g[u].size() - 1;
                    for (ll i = 1; i < m; i++) {
                        dp[u][i] = 1;
                    }
                } else {
                    dp[u][0] = 2 * g[u].size() + dp[p][0];
                    for (int i = 1; i < m; ++i) {
                        dp[u][i] = min(dp[p][i - 1] + 2, dp[p][i] + 2 * ll(g[u].size()));
                    }
                }
                dfs(u, v);
            }
        };
        dfs(0, -1);
        while (q--) {
            ll x, y;
            cin >> x >> y;
            x--;
            if (x == 0) {
                cout << 0 << endl;
            } else if (y >= m) {
                cout << layer[x] << endl;
            } else {
                cout << dp[fa[x]][y] + 1 << endl;
            }
        }
    }
    return 0;
}