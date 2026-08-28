/*
Author: kornkin
Description: Prefix Sum + Graph Knowledge (Tree)
*/
#include<bits/stdc++.h>
using namespace std;

const int MAX_SZ = 2e3;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q; cin >> n >> m >> q;

	vector<bitset<MAX_SZ + 1>> grid (MAX_SZ + 1);
	vector<vector<int>> pref (MAX_SZ + 1, vector<int>(MAX_SZ + 1));
	vector<vector<int>> horE (MAX_SZ + 1, vector<int>(MAX_SZ + 1));
	vector<vector<int>> verE (MAX_SZ + 1, vector<int>(MAX_SZ + 1));

	for(int i = 1; i <= n; i++){
		string row; cin >> row;
		for(int j = 1; j <= m; j++){
			grid[i][j] = row[j - 1] == '1';

			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + grid[i][j];
			horE[i][j] = horE[i - 1][j] + horE[i][j - 1] - horE[i - 1][j - 1] + (grid[i][j] & grid[i - 1][j]);
			verE[i][j] = verE[i - 1][j] + verE[i][j - 1] - verE[i - 1][j - 1] + (grid[i][j] & grid[i][j - 1]);
		}
	}

	while(q--){
		int a,b,c,d; cin >> a >> b >> c >> d;

		//Components = Vertices - Edges (Only Tree)
		int ans = pref[c][d] - pref[a - 1][d] - pref[c][b - 1] + pref[a - 1][b - 1]; // Count Vertices
	
		ans -= horE[c][d] - horE[a][d] - horE[c][b - 1] + horE[a][b - 1]; // Subtract Horizontal Edges
		ans -= verE[c][d] - verE[c][b] - verE[a - 1][d] + verE[a - 1][b]; // Subtract Vertical Edges
	
		cout << ans << '\n';
	}

	return 0;
}	