#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int a,b,x,y; cin >> a >> b >> x >> y;

        int ans = 0;

        if(a <= b){
            if(x <= y) {
                ans = (b - a) * x;
            }else {
                if(a%2) ans += x, a++;
                ans += ceil(float(b - a) / 2.0) * y;
                ans += floor(float(b - a) / 2) * x;
            }
        }else {
            if(a - b > 1 || !(a%2)){
                ans = -1;
            } else {
                ans = y;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}