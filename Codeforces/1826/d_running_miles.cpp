#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n]; 
        
        for(int i = 0; i < n; i++) cin >> arr[i];

        ll pref_max[n], suff_max[n];
        pref_max[0] = suff_max[0] = 0;
        for(int i = 0; i < n; i++){
            pref_max[i] = arr[i] + i;
            suff_max[i] = arr[i] - i;
        }

        for(int i = 1; i < n; i++) {
            pref_max[i] = max(pref_max[i], pref_max[i-1]);
            suff_max[n - i - 1] = max(suff_max[n - i - 1], suff_max[n - i]);
        }

        ll ans = 0;
        for(int i = 1; i < n - 1; i++) ans = max(ans, pref_max[i - 1] + arr[i] + suff_max[i + 1]);
        cout << ans << '\n';
    }

    return 0;
}

/*
4
5
5 1 4 2 3
4
1 1 1 1
6
9 8 7 6 5 4
7
100000000 1 100000000 1 100000000 1 100000000

*/