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
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    rep(i, 0, n-1) cin >> a[i];

    vector<int> b(m);
    rep(i, 0, m-1) cin >> b[i];

    sort(all(a));
    sort(all(b));

    int cnt = 0;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(abs(a[i] - b[j]) <= k) 
            cnt++, i++, j++;
        else if(a[i] > b[j]) j++;
        else i++;
    }

    print(cnt);
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
