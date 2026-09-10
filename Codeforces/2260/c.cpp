#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        int s = x + y;
        int ans = 0;

        bool ch = 1;
        for(int i = 30; i >= 0; i--){
            int xt = (x >> i) & 1;
            int st = (s >> i) & 1;

            if(ch){
                if(xt && st){
                    ans += 1 << i;
                }else if(xt && !st) ch = 0;
            }else {
                if(st) ans += 1 << i;
            }
        }

        cout << s << " " << x - ans << '\n';
    }

    return 0;
}