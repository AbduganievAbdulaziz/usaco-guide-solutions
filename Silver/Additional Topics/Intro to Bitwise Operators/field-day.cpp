
#include <bits/stdc++.h>
#define endl '\n'
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
    int c, n;
    cin >> c >> n;
    vector<int> team(n), min_edits(1 << c, INT_MAX);
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(auto ch : s){
            team[i] *= 2;
            team[i] += (ch == 'G');
        }
        min_edits[team[i]] = 0;
    }
    for(int pos = 0; pos < c; pos++){
        for(int i = 0; i < (1 << c); i++){
            if(min_edits[i] != INT_MAX){
                min_edits[i ^ (1 << pos)] = min(min_edits[i ^ (1 << pos)], min_edits[i] + 1);
            }
        }
    }
    for(int i = 0; i < n; i++)
        cout << c - min_edits[team[i] ^ ((1 << c) - 1)] << endl;
}

signed main(){
    //setIO("");
    int tt = 1;
    //cin >> tt;
    while(tt --){
        solve();
    }
    return 0;
}
