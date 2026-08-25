#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);

    int t; cin >> t;

    while(t--){
        int n, cnt = 0; cin >> n;
        int prefix[n + 1];
        memset(prefix, 0, sizeof(prefix));
        
        string arr; cin >> arr;
        for(int i = 1; i <= n; i++){
            int j = arr[i - 1] - '0';
            prefix[i] = prefix[i - 1] + j; 

            for(int k = i; k >= j && k > 0; k--){
                int sum = prefix[i] - prefix[i - k];
                if(sum == k) cnt++;
                else if(sum > k) break;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}

/*
3
3
120
5
11011
6
600005

*/