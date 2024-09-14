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
    vector<vector<vector<pair<int,int>>>> grid(n, vector<vector<pair<int,int>>>(n));
    vector<vector<bool>> lit(n, vector<bool>(n)), visited(n, vector<bool>(n));
    int d[][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
    for(int i = 0, x, y, a, b; i < m; i++){
        cin >> x >> y >> a >> b;
        x--; y--; a--; b--;
        grid[x][y].push_back(make_pair(a, b));
    }
    queue<int> qx, qy;
    qx.push(0);
    qy.push(0);
    lit[0][0] = visited[0][0] = true;
    int x, y;
    while(!qx.empty()){
        x = qx.front();
        y = qy.front();
        qx.pop(); qy.pop();
        for(auto [r, c] : grid[x][y]){
            lit[r][c] = true;
            if(visited[r][c])
                continue;
            for(auto [dr, dc] : d){
                int nr = r + dr;
                int nc = c + dc;
                if(min(nr, nc) >= 0 && max(nr, nc) < n && visited[nr][nc]){
                    visited[r][c] = true;
                    qx.push(r);
                    qy.push(c);
                    break;
                }
            }
        }
        for(auto [dx, dy] : d){
            int nx = x + dx;
            int ny = y + dy;
            if(min(nx, ny) >= 0 && max(nx, ny) < n && lit[nx][ny] && !visited[nx][ny]){
                visited[nx][ny] = true;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans += lit[i][j];
    cout << ans << endl;
}

signed main(){
    setIO("lightson");
    int tt = 1;
    //cin >> tt;
    while(tt --){
        solve();
    }
    return 0;
}
