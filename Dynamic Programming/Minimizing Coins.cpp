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
typedef vector<vector<bool>> vii;
 
/*****User defined function*****/
int mod = 1e9+7;
int inf = 1e9+5;
 
void solve() {
    int n, x;
    cin >> n >> x;
 
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
 
    vector<int> dp(x+1, inf);
    dp[0] = 0;
    rep(i, 0, n) {
        rep(j, a[i], x+1) {
            dp[j] = min(dp[j], 1 + dp[j-a[i]]);
        }
    }
 
    if(dp[x] == inf) 
        print(-1);
    else
        print(dp[x]);
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