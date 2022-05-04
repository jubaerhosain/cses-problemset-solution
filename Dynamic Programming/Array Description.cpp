#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define rep(i, s, n)  for(int i = s; i < n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
int mod = 1e9+7;
const int N = 1e5+5;
ll dp[N][105];
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
 
    if(a[0] != 0)
        dp[0][a[0]] = 1;
    else        
        rep(i, 1, m+1) dp[0][i] = 1;
 
    rep(i, 1, n) {
        if(a[i] == 0) {
            rep(j, 1, m+1) {
                ll x, y;
                x = y = 0;
                if(j > 1)
                    x = dp[i-1][j-1];
                if(j < m)
                    y = dp[i-1][j+1];
                dp[i][j] = (x + y + dp[i-1][j]) % mod;
            }
        } else {
            int j = a[i];
            ll x, y;
            x = y = 0;
            if(j > 1)
                x = dp[i-1][j-1];
            if(j < m)
                y = dp[i-1][j+1];
            dp[i][j] = (x + y + dp[i-1][j]) % mod;
        }
    }
 
    ll ans = 0;
    rep(i, 1, m+1)
        ans = (ans + dp[n-1][i]) % mod;
 
    print(ans);
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