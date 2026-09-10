#include<bits/stdc++.h>
using namespace std; 

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int x, y, k; cin >> x >> y >> k;

        int sum = 0;

        int i = 0;
        for(; y - x >= x + i && i < k; i++){
            sum += (y+i) % (x+i);    
        } 
        i++;
        sum += ((y+i) % (x+i)) * (k - i + 1);

        cout << sum << '\n';
    }

    return 0;
}