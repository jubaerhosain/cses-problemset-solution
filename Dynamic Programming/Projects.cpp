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
const int N = 2e5+5;
 
ll dp[N];
struct Node {
    ll p;
    int a, b;
};
 
bool cmp(Node &x, Node &y) {
    return x.b < y.b;
}
 
void solve() {
    int n;
    cin >> n;
 
    vector<Node> v(n);
    rep(i, 0, n-1) 
        cin >> v[i].a >> v[i].b >> v[i].p;
 
    sort(all(v), cmp);
 
    vector<int> inx;
    for(auto it: v) inx.push_back(it.b);
 
    dp[0] = v[0].p;
    rep(i, 1, n-1) {
        int j = lower_bound(all(inx), v[i].a) - inx.begin() - 1;
        if(j < 0)
            dp[i] = max(dp[i-1], v[i].p);
        else 
            dp[i] = max(dp[i-1], dp[j] + v[i].p);
    }
 
    print(dp[n-1]);
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