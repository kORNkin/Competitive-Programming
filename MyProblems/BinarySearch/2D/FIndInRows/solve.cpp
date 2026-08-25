/*
    Problem: Find In Rows
    Solution: 2D MergSort + 2D Binary Search
    Time: O(mn(log(m)) + log(m * n))
*/

#include<bits/stdc++.h>
using namespace std;

int m, n;
int arr[1000][1000];

void Merge(int l, int r){
    if(l >= r)
        return;
    
    int m = (l + r) >> 1;
    Merge(l, m);
    Merge(m + 1, r);

    int ls = (m - l + 1) * n, rs = (r - m) * n; 
    int L[ls], R[rs];
    for(int i = l; i <= m; i++) for(int j = 0; j < n; j++) L[j + (i - l) * n] = arr[i][j];
    for(int i = m + 1; i <= r; i++) for(int j = 0; j < n; j++) R[j + (i - m - 1) * n] = arr[i][j];

    int i = 0, j = 0, a = l, b = 0;
    while(i < ls && j < rs){
        if(L[i] <= R[j]) arr[a][b] = L[i], i++;
        else arr[a][b] = R[j], j++;
        b++;
        if(b == n) b -= n, a++;
    }

    while(i < ls){
        arr[a][b] = L[i];
        i++;
        b++;
        if(b == n) b -= n, a++;
    }
    while(j < rs){
        arr[a][b] = R[j];
        j++;
        b++;
        if(b == n) b -= n, a++;
    }
}

bool Find(int tar){
    //Find row
    int l = 0, r = m - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(arr[mid][n - 1] < tar) l = mid + 1;
        else r = mid;
    }
    
    int row = l;

    //Find in the column
    l = 0, r = n - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(arr[row][mid] < tar) l = mid + 1;
        else r = mid;
    }
    
    if(arr[row][l] == tar) return true;
    return false;
 }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) cin >> arr[i][j];
    
    Merge(0, m - 1);
    
    int tar; cin >> tar;
    while(tar != -1) {
        cout << tar << " is in array? " << (Find(tar) ? "true\n" : "false\n");
        cin >> tar;
    }
    return 0;
} 

/*
5 4
5 8 9 12
1 4 6 7
2 3 10 11
21 22 24 29
13 15 16 18
22

1 2 3 4 
5 6 7 8 
9 10 11 12 
13 15 16 18 
21 22 24 29 
*/