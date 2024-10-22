
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
    int n;
    cin >> n;
    vector<int> next(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> next[i];
    vector<bool> visited(n + 1);
    vector<int> trace;
    int ans = 0;
    function<void(int)> dfs = [&](int node){
        if(visited[node]){
            for(int i = 1; i <= trace.size(); i++)
                if(trace[trace.size() - i] == node){
                    ans += i;
                    return;
                }
            return;
        }
        visited[node] = true;
        trace.push_back(node);
        dfs(next[node]);
    };
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            trace.clear();
            dfs(i);
        }
    }
    cout << ans << endl;
}

signed main(){
    setIO("shuffle");
    int tt = 1;
    //cin >> tt;
    while(tt --){
        solve();
    }
    return 0;
}
