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
    int n, cows, roads;
    cin >> n >> cows >> roads;
    vector<vector<bool>> farm(n, vector<bool>(n));
    vector<vector<bool>> visited;
    map<pair<double,double>,bool> roadExist;
    int d[][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
    for(int i = 0, r, c, nr, nc; i < roads; i++){
        cin >> r >> c >> nr >> nc;
        r--; c--; nr--; nc--;
        roadExist[make_pair((r + nr)/2., (c + nc)/2.)] = true;
    }
    for(int i = 0, r, c; i < cows; i++){
        cin >> r >> c;
        r--; c--;
        farm[r][c] = true;
    }
    int ans = 0, metCows;
    function<void(int,int)> floodFill = [&](int r, int c){
        if(visited[r][c])
            return;
        visited[r][c] = true;
        if(farm[r][c])
            metCows++;
        for(auto [dr, dc] : d){
            int nr = r + dr;
            int nc = c + dc;
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && !roadExist[make_pair((r + nr)/2., (c + nc)/2.)])
                floodFill(nr, nc);
        }
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!farm[i][j])
                continue;
            metCows = 0;
            visited.assign(n, vector<bool>(n, false));
            floodFill(i, j);
            ans += cows - metCows;
        }
    }
    cout << ans/2 << endl;
}

signed main(){
    setIO("countcross");
    int tt = 1;
    //cin >> tt;
    while(tt --){
        solve();
    }
    return 0;
}
