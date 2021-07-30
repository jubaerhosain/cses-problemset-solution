#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//not for interactive
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef pair<int, int> pii;

/*****User defined function*****/
const int N = 2e5+5;

void solve() {
    int n;
    cin >> n;
    
    ll sum = 0, mx = 0;
    rep(i, 1, n) {
        ll x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }

    cout << max(sum, 2*mx) << endl;
    
    //suppose n = 5
    //order 1st: 1, 2, 3, 4, 5
    //order 2nd: 5, 3, 2, 1, 3
    //the cannot read a book same time
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
