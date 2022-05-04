//residual capacity = capacity - flow
//reverse edge(initialy 0)
//augmenting path
//complexity EV^2
//residual edges exixts to "undo" bad augmenting path
//which do not lead to a maximum flow
 
#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
int inf = 1e9+5;
int mod = 1e9+7;
const int N = 1e3+5;
int n, m;
char g[N][N];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; //D, U, R, L
 
bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}
 
void solve() {
    cin >> n >> m;
 
    pii src, dst;
    rep(i, 0, n-1) rep(j, 0, m-1) {
        cin >> g[i][j];
        if(g[i][j] == 'A') src = {i, j};
        else if(g[i][j] == 'B') dst = {i, j};
    }
 
    map<pii, pair<pii, char>> parent;
 
    queue<pii> q;
    q.push(src);
    g[src.first][src.second] = '#';
    while(!q.empty()) {
        pii u = q.front();
        q.pop();
 
        rep(i, 0, 3) {
            int x = u.first + dir[i][0];
            int y = u.second + dir[i][1];
            if(valid(x, y) && g[x][y] != '#') {
                char ch;
                if(i == 0) ch = 'D';
                else if(i == 1) ch = 'U';
                else if(i == 2) ch = 'R';
                else ch = 'L';
 
                g[x][y] = '#';
                q.push({x, y});
                parent[{x, y}] = {u, ch};
                pii curr = {x, y};
                if(curr == dst)
                    break;
            }
        }
    }
 
    if(g[dst.first][dst.second] == 'B') {
        print("NO");
        return;
    }
 
 
    string ans;
    for(pii v = dst; v != src; v = parent[v].first) {
        ans += parent[v].second;
    }
 
    reverse(ans.rbegin(), ans.rend());
 
    print("YES");
    print(ans.size());
    print(ans);
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(16);
 
    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
} 