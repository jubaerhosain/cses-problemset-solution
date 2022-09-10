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
typedef vector<vector<ll>> vii;
 
/*****User defined function*****/
ll inf = 1e17+5;
int mod = 1e9+7;
const int N = 1e5+5;
vector<int> g[N];
int in_degree[N];
 
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        in_degree[v]++;
        g[u].push_back(v);
    }
 
    queue<int> q;
    rep(i, 1, n) {
        if(in_degree[i] == 0)
            q.push(i);
    }
 
    vector<int> ans;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
 
        for(int v: g[u]) {
            in_degree[v]--;
            if(in_degree[v] == 0)
                q.push(v);
        }
    }
 
    //has cycle
    if(ans.size() != n) {
        print("IMPOSSIBLE");
        return;
    }
 
    for(int i: ans) cout << i << " ";
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