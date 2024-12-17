#include <bits/stdc++.h>
using namespace std;
int main () {
    int t;
    cin >> t;
    vector<vector<int>> ans;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > g(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> ans(n);
        int cnt = 1;
        ans[0] = cnt;
        function <void(int, int)> dfs = [&](int v, int p) {
            for (int u : g[v]) {
                if (u == p) continue;
                ans[u] = ++cnt;
                while (ans[u] != ans[v] + 1 && (ans[u] % 2 != ans[v] % 2 || ans[u] - ans[v] == 2)) {
                    ans[u] = ++cnt;
                }
                dfs(u, v);
            }
        };
        dfs(0, 0);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}