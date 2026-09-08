#include <bits/stdc++.h>
using namespace std;
// #define int long long 
struct Topo{
    int l, r; 
    vector<int> topo;
    bool ch;
};

Topo topo(int src, vector<int> g[], int deg[], bool vis[]){
    queue<int> q;
    q.push(src);

    vector<int> ans;

    int mx = src, mn = src;

    while(!q.empty()){
        int n = q.front();
        q.pop();
        if(vis[n]){
            return {0, 0, ans, 1};
        }

        ans.push_back(n);
        mn = min(mn, n);
        mx = max(mx, n);
        vis[n] = 1;
        sort(g[n].begin(), g[n].end());
        for(int v:g[n]){
            deg[v]--;
            if(deg[v] == 0){
                q.push(v);
            }
        }
    }

    return {mn, mx, ans, 0};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>> t;

    while(t--){
        int n,m; cin >> n >> m;
        vector<int> g[n + 5];
        int deg[n + 5]; 
        memset(deg, 0, sizeof(deg));

        int arr[n + 5];
        for(int i = 1; i <= n; i++) arr[i];
        
        while(m--){
            int l, r; cin >> l >> r;
            int tmp[r - l + 2];
            for(int i = l; i <= r; i++){
                cin >> tmp[i - l];
                if(i > l){
                    g[tmp[i - l - 1]].push_back(tmp[i - l]);
                    deg[tmp[i - l]]++;  
                }
            }
        }
        
        bool vis[n+1];
        memset(vis, 0, sizeof(vis));
        bool chk = 0;
        
        for(int i = 1; i <= n; i++){
            //cout << deg[i] << ' ';
            if(!vis[i] && deg[i] == 0){
                chk = 1;
                Topo res = topo(i, g, deg, vis);

                if(res.ch){
                    chk = 0;
                    break;
                }else {
                    for(int j = res.l; j <= res.r; j++){
                        arr[res.topo[j - res.l]] = j;
                    } 
                }
            }
        }

        if(!chk) cout << "-1\n";
        else {
            for(int i = 1; i <= n; i++) cout << arr[i] << ' '; 
            cout << '\n';
        }
    }

    return 0;
}
/*
1
7 3
1 4 3 1 4 2
3 6 3 5 4 6
2 7 3 5 4 7 6 2


1
8 4
3 5 5 4 3
1 3 1 3 2
4 7 5 4 6 7
4 8 5 4 8 6 7
*/