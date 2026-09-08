#include<bits/stdc++.h>
using namespace std;

struct Student{
    int time, floor, streak, state;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;

    unordered_map<string, Student> mp;
    unordered_map<string, long long int> pt;

    while(n--){
        int t, f; string name;
        cin >> t >> name >> f;

        if(mp.count(name)){
            int diff = f - mp[name].floor;
            if(abs(diff) == 1){
                if(t - mp[name].time <= 60 && (diff*mp[name].state >= 0)){
                    pt[name] += (5 + (diff + 1)*2.5) * mp[name].streak;
                    mp[name].streak++;
                } else {
                    pt[name] += 5 + (diff + 1)*2.5;
                    mp[name].streak = 1;
                }
                mp[name].state = diff;
            }else mp[name].streak = 1;
            mp[name].time = t;
            mp[name].floor = f;
        }else mp[name] = {t, f, 1, 0};

        cout << mp[name].state << ' ' << mp[name].streak << '\n';
    }

    while(m--){
        string name; cin >> name;   
        cout << name << " " << pt[name] << " ";
        if(pt[name] >= 100) cout << "A hug from Pen Pen\n";
        else if(pt[name] >= 50) cout << "Waive the summer holiday HW\n";
        else if(pt[name] >= 20) cout << "Waive a HW\n";
        else cout << "No Award\n";
    }

    return 0;   
}