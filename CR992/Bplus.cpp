/*
At some point in the development of this problem, the following alternative statement appeared: we need to minimize the total number of operations of both types. How to solve this problem?
*/
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
                if (i - n == 1) {
                    ans = 2 * ans - 2;
                } else {
                    ans = 2 * ans - 1;
                }
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
