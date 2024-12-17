#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool found = false;
        for (int i = 0; i < n; i++) {
            bool canWin = true;
            for (int j = 0; j < n; j++) {
                if (i != j && abs(a[i] - a[j]) % k == 0) {
                    canWin = false;
                    break;
                }
            }
            if (canWin) {
                cout << "YES" << endl;
                cout << i + 1 << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "NO" << endl;
        }
    }
    return 0;
}