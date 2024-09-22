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
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int,int>>> adj(n + 1);
    vector<bool> visited;
    for(int i = 0, u, v, r; i < n - 1; i++){
        cin >> u >> v >> r;
        adj[u].push_back(make_pair(v, r));
        adj[v].push_back(make_pair(u, r));
    }
    int k, v, ans, inf = 2e9;
    function<void(int,int)> dfs = [&](int node, int rel){
        if(visited[node])
            return;
        visited[node] = true;
        if(rel >= k && rel != inf)
            ans++;
        for(auto [neighbor, nextRel] : adj[node])
            dfs(neighbor, min(rel, nextRel));
    };
    while(q--){
        cin >> k >> v;
        visited.assign(n + 1, false);
        ans = 0;
        dfs(v, inf);
        cout << ans << endl;
    }
}

signed main(){
    setIO("mootube");
    int tt = 1;
    //cin >> tt;
    while(tt --){
        solve();
    }
    return 0;
}
