#include <bits/stdc++.h>
using ll=long long;
const ll INF=1e9;
const int MOD=1e9+7;
using namespace std;
struct card
{
    int l;
    int r;
    ll d;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    vector<card>optr(m+1);
    for(int i=1;i<=m;i++)
    {
        cin>>optr[i].l>>optr[i].r>>optr[i].d;
    }     
    vector<int>card_cnt(m+2,0);
    for(int i=1;i<=k;i++){    //Diffrence array for the 'K' master cards.
        int x,y;
        cin>>x>>y;
        card_cnt[x]++;
        card_cnt[y+1]--;
    }
    for(int i=1;i<=m ;i++) // Prefix sum for the 'K' master cards.
    {
        card_cnt[i]+=card_cnt[i-1];
    }
    vector<ll>box_diff(n+2,0);
    for(int i=1;i<=m;i++)
    {
        box_diff[optr[i].l]+=1LL*optr[i].d*card_cnt[i];
        box_diff[optr[i].r+1]-=1LL*optr[i].d*card_cnt[i];
    }
    for(int i=1;i<=n;i++)   //Prefix sum for the Box_differnce array.
    {                       // How much increase in each element ;
        box_diff[i]+=box_diff[i-1];
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]+box_diff[i+1]<<(i==n-1?"\n":" ");
    }
    return 0;
}