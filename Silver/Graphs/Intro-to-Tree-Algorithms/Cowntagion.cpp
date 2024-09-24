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
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1);
    for(int i = 0, u, v; i < n - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    function<void(int)> dfs = [&](int node){
        visited[node] = true;
        int nodes_around = 0, x = 1;
        for(auto neighbor : adj[node]){
            if(!visited[neighbor]){
                ans++;
                nodes_around++;
                dfs(neighbor);
            }
        }
        while(x < nodes_around + 1){
            ans++;
            x <<= 1;
        }
    };
    dfs(1);
    cout << ans << endl;
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
