#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(c <= b && a <= d){
        cout << max(a,max(b,max(c, d))) - min(a,min(b,min(c, d)));
    }else {
        cout << b - a + d - c;
    }
    return 0;

}