#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int arr[n]; for(int &a : arr) cin >> a;

    vector<int> tails;

    for(int i = 0; i < n; i++){
        auto it = lower_bound(tails.begin(), tails.end(), arr[i]);

        if(it == tails.end()) tails.push_back(arr[i]);
        else *it = arr[i];
    }

    cout << tails.size();

    return 0;
}