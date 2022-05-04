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
const int N = 1e5+5;
vector<int> g[N];
int in[N], low[N], scc[N];
stack<int> stk;
bool used[N], on_stack[N];
int scc_cnt = 0, timer = 0;
 
void dfs(int u) {
    stk.push(u);
    in[u] = low[u] = ++timer;
    used[u] = on_stack[u] = true;
 
    for(int v: g[u]) {
        if(used[v] && on_stack[v]) {
            low[u] = min(low[u], in[v]);
        } else if(!used[v]) {
            dfs(v);
            if(on_stack[v]) 
                low[u] = min(low[u], low[v]);
        }
    }
 
    if(in[u] == low[u]) {
        ++scc_cnt;
        
        while(!stk.empty()) {
            int v = stk.top();
            stk.pop();
            on_stack[v] = false;
            scc[v] = scc_cnt;
            if(v == u) break;
        }
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
 
    rep(i, 1, n) {
        if(!used[i]) 
            dfs(i);
    }
 
    print(scc_cnt);
    rep(i, 1, n) cout << scc[i] << " ";
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