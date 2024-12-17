#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int ans = 1;
        for (int i = 1; ; i = 2 * i + 2, ans++){
            if(i >= n){
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
