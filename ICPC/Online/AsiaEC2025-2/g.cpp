#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);   
    cin.tie(0);

    int n, m; cin >> n >> m;
    int arr[] = {5,4,3,2,1};
    int a[m], b[m];
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < m; j++){
            if(arr[a[j]] > arr[b[j]]){
                swap(arr[a[j]], arr[b[j]]);
                for(int a : arr) cout << a << ' ';
                cout << '\n';
            }
        } cout << "-------\n";
    }


    return 0;
}