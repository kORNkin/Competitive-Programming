#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int n; string s; cin >> n >> s;

    int l = 0, r = 1e18;

    pair<int, int> pref[n + 1];
    pref[0] = {0, 0};

    for(int i = 1; i <= n; i++){
        if(s[i - 1] == 'U'){
            pref[i] = {pref[i-1].first, pref[i-1].second + 1};
        }else if(s[i - 1] == 'D'){
            pref[i] = {pref[i-1].first, pref[i-1].second - 1};
        }else if(s[i - 1] == 'R'){
            pref[i] = {pref[i-1].first + 1, pref[i-1].second};            
        }else if(s[i - 1] == 'L'){
            pref[i] = {pref[i-1].first - 1, pref[i-1].second};
        }
        // cout << pref[i].first << ' ' << pref[i].second << '\n';
    }

    while(l < r){
        int m = l + ((r - l)>>1);
        
        int difx = (m / n) * pref[n].first; 
        int dify = (m / n) * pref[n].second; 
        
        difx += pref[m%n].first;
        dify += pref[m%n].second;
    
        int sum = abs(x2 - x1 - difx) + abs(y2 - y1 - dify);
        if(sum <= m) r = m;
        else l = m + 1;
    }

    if(l > 5e17) cout << "-1";
    else {
        cout << l;
    }

    return 0;
}