#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);

    int t; cin >> t;

    while(t--){
        long long n, ans = 0, sum = 0; cin >> n;
        
        string arr; cin >> arr;
        unordered_map<int, long long> mp;

        mp[0]++;
        for(int i = 0; i < n; i++) {
            sum += arr[i] - '0';
            ans += mp[sum - i - 1];
            mp[sum - i - 1]++;
        }
        cout << ans << '\n';
    }

    return 0;
}

/*
3
3
120
5
11011
6
600005

*/