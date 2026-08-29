#include<bits/stdc++.h>
using namespace std;

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    std::ifstream read("diamond.in");
    std::ofstream out("diamond.out");

    int n, k; read >> n >> k;

    int arr[n + 1];

    for(int i = 0; i < n; i++) read >> arr[i];
    
    sort(arr, arr+n);
    arr[n] = INT_MAX;

    int range[n], suff_mx_range[n + 1];
    memset(range, 0, sizeof(range));
    memset(suff_mx_range, 0, sizeof(suff_mx_range));
    for(int i = 0; i < n; i++){
        int tar = arr[i] + k;

        int l = i + 1, r = n;
        while(l < r){
            int mid = (l + r) >>1;
            if(arr[mid] > tar) r = mid;
            else l = mid + 1;
        }
        range[i] = l - i;   
    }
    
    for(int i = n - 1; i >= 0; i--) {
        suff_mx_range[i] = max(suff_mx_range[i + 1], range[i]);
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, range[i] + suff_mx_range[range[i] + i]);
    }

    out << ans;

    return 0;   
}