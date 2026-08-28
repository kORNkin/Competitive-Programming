/*
Author: kornkin
Description: Difference arrays
*/
#include<bits/stdc++.h>
using namespace std;

struct OP{
    long long l, r, d;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n,m,k; cin >> n >> m >> k;

    long long arr[n]; 

    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<OP> op;

    for(int i = 0; i < m; i++){
        long long l, r, d; cin >> l >> r >> d;
        op.push_back({l, r, d});
    }

    long long cnt[m];
    long long in[max(n,m)], out[max(n,m)]; 
    memset(cnt, 0, sizeof(cnt));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));

    while(k--) {
        long long x, y; cin >> x >> y;
        in[x-1]++;
        out[y-1]++;
    }   

    long long cur = 0;
    for(int i = 0; i < m; i++){
        cur += in[i];
        cnt[i] = cur;
        cur -= out[i];
    }

    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));

    for(int i = 0; i < m; i++){
        in[op[i].l - 1] += op[i].d * cnt[i];
        out[op[i].r - 1] += op[i].d * cnt[i];
    }

    cur = 0;
    for(int i = 0; i < n; i++){
        cur += in[i];
        arr[i] += cur;
        cur -= out[i];
    }

    for(int i = 0; i < n; i++) cout << arr[i] << ' ';

    return 0;
}

/*
4 3 6
1 2 3 4
1 2 1
2 3 2
3 4 4
1 2
1 3
2 3
1 2
1 3
2 3

4 3 6
1 2 3 4
1 2 1
2 3 2
3 4 4
1 2
1 3
2 3
1 2
1 3
2 3
*/