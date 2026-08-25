// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int t; cin >> t;
//     while(t--){
//         int n; cin >> n;
//         int px, py, qx, qy; cin >> px >> py >> qx >> qy;

//         vector<pair<long double, long double>> rng;
//         long double x, y; cin >> x;
//         rng.push_back({x, x});
//         for(int i = 1; i < n; i++){
//             cin >> y;
//             vector<pair<long double, long double>> tmp;
//             for(auto i:rng){
//                 tmp.push_back({min(abs(i.first - y), min(abs(i.second - y), min(i.first + y, i.second + y))), 
//                                max(abs(i.first - y), max(abs(i.second - y), max(i.first + y, i.second + y)))});
//             }
//             sort(rng.begin(), rng.end(),[](const pair<long double, long double>& a, const pair<long double, long double>& b) {
//                 if(a.first == b.first) return a.second > b.second;
//                 return a.first < b.first;});

//             long double xx = tmp[0].first, yy = tmp[0].second;
//             rng.clear();
//             rng.push_back({xx, yy});
//             for(int i = 1; i < tmp.size(); i++){
//                 if(tmp[i].first >= xx && tmp[i].first <= yy && tmp[i].second >= yy) yy = tmp[i].second;
//                 else if(tmp[i].first > yy){
//                     rng.push_back({xx, yy});
//                     xx = tmp[i].first, yy = tmp[i].second;
//                 }
//             }
//         }

//         long double dis = sqrt(pow(px - qx, 2) + pow(py - qy, 2));
//         bool ch = 0;
//         for(auto i : rng){
//             if(dis >= i.first && dis <= i.second){
//                 ch = 1; break;
//             }
//         }
//         cout << (ch? "Yes\n" : "No\n");
//     }
//     return 0;
// }
// Codeforces - Round 1035 - Div. 2 - Problem B - Line Segments

// Link to this problem: https://codeforces.com/contest/2119/problem/B

// Date: 9 July 2025
// Score: 100/100

// Solution guidance by P'Non

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i;
    int t;
    cin >> t;
    for (i = 0; i < t; i++) {
        int j;
        int n;
        long long p1, p2, q1, q2, sum = 0, mx = 0;
        
        cin >> n;
        cin >> p1 >> p2 >> q1 >> q2;
        
        for (j = 1; j <= n; j++) {
            long long a;
            cin >> a;
            sum += a;
            mx = max(mx, a);
        }

        long long diff = pow(p1 - q1, 2) + pow(p2 - q2, 2);

        // 2*mx - sum = mx - (sum - mx)
        if ((pow((mx > sum - mx)*(2*mx - sum), 2) <= diff) && (diff <= pow(sum, 2))) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout << "\n";
    }
    return 0;
}