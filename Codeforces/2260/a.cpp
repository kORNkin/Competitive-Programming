#include<bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int cnt = 0; 
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(!arr[i]) cnt++;
        }

        if(n == 1) cout << (arr[0] ? "-1\n" : "0\n");
        else if(n == 2) cout << (cnt <= 1? "-1\n" : "0\n");
        else {
            if(arr[0] && arr[n - 1]) cout << (cnt >= 2? "2\n" : "-1\n");
            else if(arr[0] || arr[n - 1]) cout << (cnt >= 2? "1\n" : "-1\n");
            else cout << "0\n";
        }
    }

    return 0;
}