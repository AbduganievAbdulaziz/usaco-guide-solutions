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
    int n, sz = 3000;
    cin >> n;
    vector<vector<bool>> present(sz, vector<bool>(sz));
    int d[][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
    int total = 0;
    queue<int> to_place_x, to_place_y;
    for(int i = 1, x, y; i <= n; i++){
        cin >> x >> y;
        x += 1000;
        y += 1000;
        to_place_x.push(x);
        to_place_y.push(y);
        function<void(int,int)> check_around = [&](int r, int c){
            if(!present[r][c])
                return;
            int neighbors = 0, er, ec;
            for(auto [dr, dc] : d){
                int nr = r + dr;
                int nc = c + dc;
                if(present[nr][nc])
                    neighbors ++;
                else
                    er = nr, ec = nc;
            }
            if(neighbors != 3)
                return;
            to_place_x.push(er);
            to_place_y.push(ec);
        };
        while(!to_place_x.empty()){
            x = to_place_x.front();
            y = to_place_y.front();
            to_place_x.pop();
            to_place_y.pop();
            if(present[x][y])
                continue;
            present[x][y] = true;
            total++;
            check_around(x, y);
            for(auto [dx, dy] : d)
                check_around(x + dx, y + dy);
        }
        cout << total - i << endl;
    }
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
