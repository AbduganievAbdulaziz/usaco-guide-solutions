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
    int n, m;
    cin >> n >> m;
    string breed;
    cin >> breed;
    breed = ' ' + breed;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1);
    vector<int> component(n + 1);
    for(int i = 0, u, v; i < n - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int componentNum = 1;
    function<void(int)> dfs = [&](int node){
        if(visited[node])
            return;
        visited[node] = true;
        component[node] = componentNum;
        for(auto child : adj[node]){
            if(breed[child] == breed[node])
                dfs(child);
        }
    };
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            componentNum++;
        }
    }
    while(m --){
        int a, b; char c;
        cin >> a >> b >> c;
        if(breed[a] != breed[b] || breed[a] == c)
            cout << 1;
        else
            cout << (component[a] != component[b]);
    }
}

signed main(){
    setIO("milkvisits");
    int tt = 1;
    //cin >> tt;
    while(tt --){
        solve();
    }
    return 0;
}
