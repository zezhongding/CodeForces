#include<bits/stdc++.h>
using namespace std;
int main () {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        reverse(a.begin(), a.end());
        for (auto & s : a) {
            if (s == 'p') {
                s = 'q';
            } else if (s == 'q') {
                s = 'p';
            }
        }
        cout << a << endl;
    }
}