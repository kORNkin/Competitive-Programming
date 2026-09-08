#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, tar; cin >> n >> tar;
    vector<pair<int, int>> vec(n);

    for(int i = 0; i < n; i++) cin >> vec[i].first, vec[i].second = i + 1;
    
    sort(vec.begin(), vec.end());

    int a = 0, b = n - 1;
    while(a < b){
        if(vec[a].first + vec[b].first == tar) {
            cout << min(vec[a].second, vec[b].second) << ' ' << max(vec[a].second, vec[b].second);
            return 0;
        } else if(vec[a].first + vec[b].first > tar) b--;
        else a++;
    }
    cout << "IMPOSSIBLE";
    return 0;
}