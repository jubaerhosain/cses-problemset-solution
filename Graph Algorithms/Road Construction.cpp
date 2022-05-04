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
int tot_cmp, max_size;
vector<int> prnt(N, -1), rnk(N, 1);
 
int find(int u) {
    if(prnt[u] == -1) return u;
    return prnt[u] = find(prnt[u]);
}
 
void merge(int u, int v) {
    u = find(u);
    v = find(v);
 
    if(rnk[u] < rnk[v]) swap(u, v);
 
    rnk[u] += rnk[v];
    prnt[v] = u;
    max_size = max(max_size, rnk[u]);
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    tot_cmp = n;
    max_size = 1;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
 
        u = find(u);
        v = find(v);
        if(u != v) {
            merge(u, v);
            tot_cmp--;
        }
        cout << tot_cmp << ' ' << max_size << endl;
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