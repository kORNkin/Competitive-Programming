#include<bits/stdc++.h>
using namespace std;

int n, k;

int solve(int l,int r, int arr[], function<bool(int, int[])> f){
    while(l < r){
        int m = l + ((r - l + 1)>>1);
        if(f(m, arr)) l = m;
        else r = m - 1;
    }

    return l;
}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    int arr[n];
    for(int &a : arr) cin >> a;

    sort(arr, arr + n);

    cout << solve(arr[((n+1)>>1) - 1], 2 * 1e9, arr, [](int m, int arr[]) -> bool{
        long long op_use = 0;

        for(int i = ((n+1)>>1) - 1; i < n; i++){
            op_use += max(0, m - arr[i]);
        }
        return op_use <= k;
    });

    return 0;
}