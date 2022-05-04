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
int mod = 1e9+7;
int inf = mod;
const int N = 5e2+5;
ll dp[N][N];
 
void solve() {
    int a, b;
    cin >> a >> b;
 
    rep(i, 1, a) rep(j, 1, b) 
        if(i != j) dp[i][j] = inf;
 
    rep(w, 1, a) rep(h, 1, b) {
        rep(i, 1, h-1) 
            dp[w][h] = min(dp[w][h], 1 + dp[w][i] + dp[w][h-i]);
        rep(i, 1, w-1) 
            dp[w][h] = min(dp[w][h], 1 + dp[i][h] + dp[w-i][h]); 
    }
 
    print(dp[a][b]);
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