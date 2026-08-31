#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int arr[n];
        int ans = n;

        int cnt[m + 2], mode = 0, mode_idx = -1;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            cnt[arr[i]]++;
            if(arr[i]%2 == 0 && cnt[arr[i]] > mode) mode = cnt[arr[i]], mode_idx = 0;
        }

        int k = 0;
        if(mode_idx != - 1){
            int x = arr[mode_idx] / 2;
            for(int i = 0; i < n; i++){ 
                if(arr[i] == x) k++;
                else if(arr[i] > x) {
                    k++;
                    if(arr[i] == x+x) k++;
                }
            }
        }
        
        ans = max(ans, k);   
        cout << ans << '\n';
    }

    return 0;
}