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
vector<pii> g[N];
ll dist[N], disc[N];
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    rep(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }
 
    rep(i, 1, n) {
        dist[i] = inf;
        disc[i] = inf;
    }
 
    //{w, {v, cupon}}
    priority_queue<pair<ll, pii>> pq;
    pq.push({0, {1, 0}});
    dist[1] = 0;
    disc[1] = 0;
    while(!pq.empty()) {
        int d = -pq.top().first;
        int u = pq.top().second.first;
        int used = pq.top().second.second;
        pq.pop();
 
        if(used && disc[u] < d)
            continue;
        if(!used && dist[u] < d)
            continue; 
 
        for(pii it: g[u]) {
            int v = it.first;
            int c = it.second;
 
            if(used && disc[u] + c < disc[v]) {
                disc[v] = disc[u] + c;
                pq.push({-disc[v], {v, 1}});
            }
 
            if(!used && dist[u] + c/2 < disc[v]) {
                disc[v] = dist[u] + c/2;
                pq.push({-disc[v], {v, 1}});
            } 
 
            if(!used && dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                pq.push({-dist[v], {v, 0}});
            }
        }
    }
 
    print(disc[n]);
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