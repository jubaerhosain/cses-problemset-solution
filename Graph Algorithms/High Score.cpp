#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
ll inf = 1e17+5;
int mod = 1e9+7;
const int N = 1e5+5;
ll dist[N];
bool used1[N], used2[N];
vector<int> g1[N], g2[N];
 
void dfs1(int u) {
    used1[u] = true;
    for(int v: g1[u]) {
        if(!used1[v]) 
            dfs1(v);
    }
}
 
void dfs2(int u) {
    used2[u] = true;
    for(int v: g2[u]) {
        if(!used2[v]) 
            dfs2(v);
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<pair<int, pii>> edges;
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g1[u].push_back(v);
        g2[v].push_back(u);
        edges.push_back({-w, {u, v}});
    }
 
    dfs1(1);
    dfs2(n);
 
    fill(dist, dist+N, inf);
 
    dist[1] = 0;
    bool updated;
    rep(i, 1, n) {
        updated = false;
        for(auto it: edges) {
            int u = it.second.first;
            int v = it.second.second;
            int w = it.first;
            if(used1[u] && used2[v] && dist[u] != inf && dist[u] + w < dist[v]) {
                updated = true;
                dist[v] = dist[u] + w;
            }
        }
        if(!updated) break;
    }
 
    if(updated) 
        print(-1);
    else 
        print(-dist[n]);
 
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