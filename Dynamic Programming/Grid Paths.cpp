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
const int N = 1e3+5;
int dp[N][N];
 
void solve() {
    int n;
    cin >> n;
 
    vector<string> a(n);
    rep(i, 0, n) cin >> a[i];
 
    int i = 0;
    while(i < n && a[i][0] == '.') 
        dp[i][0] = 1, i++; 
        
    i = 0;
    while(i < n && a[0][i] == '.') 
        dp[0][i] = 1, i++;
 
    rep(i, 1, n) rep(j, 1, n) {
        if(a[i][j] == '.')
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
    }
 
    print(dp[n-1][n-1]);
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