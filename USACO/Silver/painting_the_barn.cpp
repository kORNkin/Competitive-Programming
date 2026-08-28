#include<bits/stdc++.h>
using namespace std;

int gph[1002][1002];
int dp[1002][1002];

int main(){
    std::ifstream read("paintbarn.in");

    int n, k; read >> n >> k;

    memset(gph, 0, sizeof(gph));
    memset(dp, 0, sizeof(dp));

    int mx = 0, my = 0;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2; read >> x1 >> y1 >> x2 >> y2;
        x1++; y1++;
        x2++; y2++;
        mx = max(mx, x2);
        my = max(my, y2);
        for(int k = x1; k < x2; k++){
            gph[k][y1]++;
            gph[k][y2]--;
        }
    }

    for(int i = 1; i <= mx; i++){
        for(int j = 1; j <= my; j++){
            gph[i][j] += gph[i][j - 1];
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + (gph[i][j] == k);
        }
    }

    //cout << dp[mx][my];
	std::ofstream("paintbarn.out") << dp[mx][my] << endl;

    return 0;
}