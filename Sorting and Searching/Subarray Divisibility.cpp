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

    vector<int> a(n);
    rep(i, 0, n-1) {
        cin >> a[i];
        a[i] %= n;
    }

    map<ll, int> mp;
    mp[0] = 1;
    ll ans = 0, prefix = 0;
    rep(i, 0, n-1) {
        prefix = (prefix + a[i]) % n;
        prefix = (prefix + n) % n;
        ans += mp[prefix];
        mp[prefix]++;
    }

    cout << ans << endl;
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
