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
const int N = 1e5+5;
int scc_no = 0;
vector<int> g[N];
int scc_map[N], used[N];
 
void dfs(int u) {
    used[u] = true;
    scc_map[scc_no] = u;
 
    for(int v: g[u]) {
        if(!used[v]) 
            dfs(v);
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    rep(i, 1, n) {
        if(!used[i]) {
            dfs(i);
            scc_no++;
        }
    }
    
    scc_no--;
    print(scc_no);
    int u = scc_map[0];
    rep(i, 1, scc_no) 
        cout << u << " " << scc_map[i] << endl;
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