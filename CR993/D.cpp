#include <bits/stdc++.h>
using namespace std;
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> loc(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (loc[a[i] - 1] == -1) {
                loc[a[i] - 1] = i;
            }
        }
        vector<int> use;
        for (int i = 0; i < n; i++) {
            if (loc[i] == -1) {
                use.push_back(i + 1);
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (loc[a[i] - 1] != i) {
                ans[i] = use.back();
                use.pop_back();
            } else {
                ans[i] = a[i];
            }
        }
        for (auto & i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}