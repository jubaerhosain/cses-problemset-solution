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
    
    vector<pii> ranges(n);
    rep(i, 0, n-1) {
        int l, r;
        cin >> l >> r;
        ranges[i] = {l, r};
    }

    sort(ranges.begin(), ranges.end());

    ll ans = 0, time = 0;
    rep(i, 0, n-1) {
        time += ranges[i].first;
        ans += ranges[i].second - time;
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
