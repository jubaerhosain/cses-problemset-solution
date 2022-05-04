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
ll inf = 1e18+5;
int mod = 1e9+7;
const int N = 1e5+5;
bool used[N];
vector<pii> g[N];
vector<ll> dist(N, inf);
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
    }
 
    memset(used, false, sizeof(used));
 
    priority_queue<pii> pq;
    pq.push({0, 1});
    dist[1] = 0;
 
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int u = p.second;
 
        if(used[u])
            continue;
 
        used[u] = true;
        for(auto it: g[u]) {
            int w = it.first;
            int v = it.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
    
    rep(i, 1, n) {
        cout << dist[i] << " ";
    }
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