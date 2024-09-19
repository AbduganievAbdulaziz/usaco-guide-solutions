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
    int n, k;
    cin >> n >> k;
    vector<vector<char>> grid(n, vector<char>(10));
    for(auto &row : grid)
        for(auto &elem : row)
            cin >> elem;
    set<pair<int,int>> visited;
    int d[][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
    bool disappeared;
    int sz;
    function<void(int,int,char,bool)> floodFill = [&](int r, int c, char col, bool rm){
        if(visited.count(make_pair(r, c)))
            return;
        visited.insert(make_pair(r, c));
        sz++;
        if(rm)
            grid[r][c] = '0';
        for(auto [dr, dc] : d){
            int nr = r + dr;
            int nc = c + dc;
            if(nr >= 0 && nr < n && nc >= 0 && nc < 10 && grid[nr][nc] == col)
                floodFill(nr, nc, col, rm);
        }
    };
    do{
        disappeared = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 10; j++){
                if(grid[i][j] != '0'){
                    sz = 0;
                    visited.clear();
                    floodFill(i, j, grid[i][j], false);
                    if(sz >= k){
                        visited.clear();
                        floodFill(i, j, grid[i][j], true);
                        disappeared = true;
                    }
                }
            }
        }
        for(int c = 0; c < 10; c++){
            for(int r = n - 1, nr; r > 0; r--){
                if(grid[r][c] != '0')
                    continue;
                nr = r - 1;
                while(nr >= 0 && grid[nr][c] == '0')
                    nr--;
                if(nr >= 0)
                    swap(grid[r][c], grid[nr][c]);
            }
        }
    }while(disappeared);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++)
            cout << grid[i][j];
        cout << endl;
    }
}

signed main(){
    setIO("mooyomooyo");
    int tt = 1;
    //cin >> tt;
    while(tt --){
        solve();
    }
    return 0;
}
