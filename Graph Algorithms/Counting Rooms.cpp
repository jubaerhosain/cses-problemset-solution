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
int inf = 1e9;
int mod = 1e9+7;
const int N = 1e3+5;
int n, m;
char g[N][N];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
 
bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}
 
void dfs(int x, int y) {
    if(!valid(x, y) || g[x][y] != '.')
        return;
 
    g[x][y] = '*';
    rep(i, 0, 3) {
        dfs(x + dir[i][0], y + dir[i][1]);
    }
}
 
void solve() {
    cin >> n >> m;
 
    rep(i, 0, n-1) rep(j, 0, m-1)
        cin >> g[i][j];
 
    int cc = 0;
    rep(i, 0, n-1) rep(j, 0, m-1)
        if(g[i][j] == '.') dfs(i, j), cc++;
 
    print(cc);
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