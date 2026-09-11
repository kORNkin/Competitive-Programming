#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    pair<int,int> arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr, arr + n, [](pair<int, int> a, pair<int, int> b){
        return (a.second == b.second) ? a.first < b.first : a.second < b.second;
    });

    int cnt = 1, end = arr[0].second; 
    for(int i = 1; i < n; i++){
        if(arr[i].first >= end) cnt++, end = arr[i].second;
    }

    cout << cnt;

    return 0;
}