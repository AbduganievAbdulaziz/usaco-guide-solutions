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
    int X, Y, K, M;
    cin >> X >> Y >> K >> M;
    vector<vector<bool>> visited(X + 1, vector<bool>(Y + 1));
    queue<int> qx, qy;
    int x, y;
    qx.push(0);
    qy.push(0);
    visited[0][0] = true;
    int ans = M, sz;
    for(int i = 0; i < K + 1; i++){
        sz = qx.size();
        for(int j = 0, dx, dy; j < sz; j++){
            x = qx.front();
            y = qy.front();
            qx.pop(); qy.pop();
            ans = min(ans, abs(x + y - M));
            if(!visited[0][y]){
                visited[0][y] = true;
                qx.push(0);
                qy.push(y);
            }
            if(!visited[x][0]){
                visited[x][0] = true;
                qx.push(x);
                qy.push(0);
            }
            if(!visited[X][y]){
                visited[X][y] = true;
                qx.push(X);
                qy.push(y);
            }
            if(!visited[x][Y]){
                visited[x][Y] = true;
                qx.push(x);
                qy.push(Y);
            }
            dx = min(abs(y - Y), x);
            dy = min(abs(x - X), y);
            if(!visited[max(x - dx, 0LL)][y + min(dx, x)]){
                visited[max(x - dx, 0LL)][y + min(dx, x)] = true;
                qx.push(max(x - dx, 0LL));
                qy.push(y + min(dx, x));
            }
            if(!visited[x + min(dy, y)][max(y - dy, 0LL)]){
                visited[x + min(dy, y)][max(y - dy, 0LL)] = true;
                qx.push(x + min(dy, y));
                qy.push(max(y - dy, 0LL));
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    setIO("pails");
    int tt = 1;
    //cin >> tt;
    while(tt --){
        solve();
    }
    return 0;
}
