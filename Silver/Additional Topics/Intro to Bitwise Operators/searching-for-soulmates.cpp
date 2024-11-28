
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

using namespace std;

const int mod = 1e9 + 7;

void setIO(string s){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve(){
    /*
    */
    int a, b;
    cin >> a >> b;
    function<int(int,int)> compute = [&](int a, int b){
        if(a == b)
            return 0LL;
        if(a > b)
            return compute((a + 1)/2, b) + (a&1) + 1;
        return min(b - a, compute(a, b/2) + (b&1) + 1);
    };
    cout << compute(a, b) << endl;
}

signed main(){
    //setIO("");
    int tt = 1;
    cin >> tt;
    while(tt --){
        solve();
    }
    return 0;
}
