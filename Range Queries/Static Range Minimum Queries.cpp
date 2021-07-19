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
const int N = 2e5+5;
int table[N][30];
 
void build_table(vector<int> &a, int n) {
    rep(i, 0, n-1) table[i][0] = a[i];
 
    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 0; (i + (1 << j) - 1) < n; i++) {
            table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1]);
        }
    }
}
 
int get_min(int l, int r) {
    int j = log2(r-l+1);
    return min(table[l][j], table[r-(1<<j)+1][j]);
}
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    vector<int> a(n);
    rep(i, 0, n-1) cin >> a[i];
 
    build_table(a, n);
 
    while(q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        print(get_min(l, r));
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
