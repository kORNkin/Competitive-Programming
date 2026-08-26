/*
Author: kornkin
Description: Prefix Sum + Math
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int t; cin >> t;

    while(t--){
        long long n, m; cin >> n >> m;

        long long med = n%2? (n+1)>>1 : n>>1;

        long long arr[n];

        vector<long long> all;
        for(int i=0; i < n; i++){
            cin >> arr[i];
            all.push_back(arr[i]%m);
            all.push_back((arr[i]%m) + m);
            all.push_back((arr[i]%m) - m);
        }

        sort(all.begin(), all.end());

        long long pref[n*3 + 1];
        pref[0] = 0;
        for(int i = 1; i <= n * 3; i++) pref[i] = pref[i - 1] + all[i - 1];
        
        long long ans = LLONG_MAX;
        long long left1, right1, left2, right2;
        if(n%2){
            for(int i = 1; i <= n * 2 + 1; i++){
                left1 = - pref[i + med - 1] + pref[i - 1];
                right1 =  pref[i + n - 1] - pref[i + med - 1];
                ans = min(ans, left1 + right1 + all[i + med - 2]);
            }
        }else {
            for(int i = 1; i <= n * 2 + 1; i++){
                left1 = - pref[i + med - 1] + pref[i - 1];
                right1 =  pref[i + n - 1] - pref[i + med - 1];
                left2 = - pref[i + med] + pref[i - 1];
                right2 =  pref[i + n - 1] - pref[i + med];
            
                ans = min(ans, min(left1 + right1, left2 + right2 + all[i + med - 1]*2));
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
/*
2
5 9
15 12 18 3 8
3 69
1 988244353 998244853

1
6 9 
15 12 18 3 8 12
*/