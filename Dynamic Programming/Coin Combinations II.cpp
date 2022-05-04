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
 
void solve() {
    int n, x;
    cin >> n >> x;
 
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];
 
    vii dp(n+1, vector<int>(x+1, 0));
    rep(i, 0, n+1) dp[i][0] = 1;
    rep(i, 1, n+1) {
        rep(j, 1, x+1) {
            if(j < a[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = (dp[i-1][j] + dp[i][j-a[i]])%mod;
        }
    }
 
    print(dp[n][x]);
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