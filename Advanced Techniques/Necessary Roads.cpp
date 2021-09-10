#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 1e5+5;
vector<int> g[N];
vector<pii> bridges;
int in[N], low[N], used[N];
int timer = 0;

void dfs(int u, int p = -1) {
    used[u] = 1;
    in[u] = low[u] = ++timer;
    
    for(int v: g[u]) {
        if(v == p) 
            continue;
        if(used[v]) {
            //this is back edge if(in[u] > in[v])
            low[u] = min(low[u], in[v]);
        } 
        else {
            //this is tree edge (u->v)
            dfs(v, u);
            if(in[u] < low[v]) 
                bridges.push_back({u, v});
            low[u] = min(low[u], low[v]);
        }
    }
}
 
void solve_problem() {
    int n, m;
    cin >> n >> m;
 
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);
 
    cout << bridges.size() << endl;
    for(auto it: bridges)
        cout << it.first << " " << it.second << endl;
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
    while(test--) solve_problem();
 
    return 0;
} 
