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
    vector<string> field(n);
    for(auto &row : field)
        cin >> row;
    vector<vector<bool>> visited;
    vector<set<pair<int,int>>> pcl(400);
    vector<int> componentNumber;
    int d[][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
    int colorNum, fCompNum, sComNum, id = 0;
    bool marked;
    function<void(int,int,int,int)> start_dfs = [&](int r, int c, int w, int h){
        function<void(int,int)> dfs = [&](int x, int y){
            if(visited[x][y])
                return;
            visited[x][y] = true;
            for(auto [dx, dy] : d){
                int nx = x + dx;
                int ny = y + dy;
                if(nx < r || nx >= r + h  || ny < c || ny >= c + w || field[nx][ny] != field[x][y])
                    continue;
                dfs(nx, ny);
            }
        };
        for(int i = r; i < r + h; i++){
            for(int j = c; j < c + w; j++){
                if(!visited[i][j]){
                    componentNumber[field[i][j] - 'A']++;
                    dfs(i, j);
                }
            }
        }
    };
    function<void(int,int,int,int)> putMark = [&](int r, int c, int w, int h){
        for(int i = r; i < r + h; i++){
            for(int j = c; j < c + w; j++){
                pcl[id].insert(make_pair(i, j));
            }
        }
        id++;
    };
    for(int w = n; w > 0; w--){
        for(int h = n; h > 0; h--){
            for(int i = 0; i + h - 1 < n; i++){
                for(int j = 0; j + w - 1 < n; j++){
                    /*
                    1. find #colors within rect
                    2. find #components of each color
                    3. check conditions
                    4. if true then mark
                    5. else skip
                    */
                    marked = false;
                    pair<int,int> fc = {i, j};
                    pair<int,int> sc = {i + h - 1, j + w - 1};
                    for(int k = 0; k < id && !marked; k++){
                        if(pcl[k].count(fc) && pcl[k].count(sc))
                            marked = true;
                    }
                    if(marked)
                        continue;
                    visited.assign(n, vector<bool>(n, false));
                    componentNumber.assign(26, 0);
                    start_dfs(i, j, w, h);
                    colorNum = 0;
                    fCompNum = -1;
                    for(int i = 0; i < componentNumber.size(); i++){
                        if(componentNumber[i] > 0){
                            colorNum++;
                            if(fCompNum == -1)
                                fCompNum = componentNumber[i];
                            else
                                sComNum = componentNumber[i];
                        }
                    }
                    if(colorNum == 2 && min(fCompNum, sComNum) == 1 && max(fCompNum, sComNum) > 1)
                        putMark(i, j, w, h);
                }
            }
        }
    }
    cout << id << endl;
}

signed main(){
    setIO("where");
    int tt = 1;
    //cin >> tt;
    while(tt --){
        solve();
    }
    return 0;
}
