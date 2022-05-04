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
const int N = 1e5+5;
bool dp[105][N];
 
void solve() {
    int n;
    cin >> n;
 
    int sum = 0;
    dp[0][0] = true;
    vector<int> a(n+1);
    rep(i, 1, n) {
        cin >> a[i];
        sum += a[i];
        dp[i][0] = true;
    }
 
    vector<int> ans;
    rep(i, 1, n) {
        rep(j, 1, sum) {
            if(j < a[i])
                dp[i][j] = dp[i-1][j];
            else    
                dp[i][j] = dp[i-1][j] | dp[i-1][j-a[i]];
 
            if(i == n && dp[i][j])
                ans.push_back(j);
        }
    }
 
    print(ans.size());
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