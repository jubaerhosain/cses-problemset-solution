#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define out(a, b)     cout << a << " " << b << endl
#define rep(i, s, n)  for(int i = s; i < n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
int mod = 1e9+7;
int inf = 1e9+5;
const int N = 1e5+5;
int dp[1005][N];
 
void solve() {
    int n, x;
    cin >> n >> x;
 
    vector<int> w(n+1), p(n+1);
    rep(i, 1, n+1) cin >> w[i];
    rep(i, 1, n+1) cin >> p[i];
 
    rep(i, 1, n+1) rep(j, 1, x+1) {
        if(j < w[i])
            dp[i][j] = dp[i-1][j];
        else
            dp[i][j] = max(dp[i-1][j], p[i] + dp[i-1][j-w[i]]);
    }
 
    print(dp[n][x]);
}   
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
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