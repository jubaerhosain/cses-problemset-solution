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
    int n , k;
    cin >> n >> k;

    int mx = 0;
    vector<int> a(n);
    rep(i, 0, n-1) {
        cin >> a[i]; 
        mx = max(mx, a[i]);
    }

    ll ans = 1e18;
    ll low = mx, high = 1e18;
    while(low <= high) {
        ll block = 1, sum = 0;
        ll mid = (low + high) / 2;

        rep(i, 0, n-1) {
            if(sum + a[i] > mid)
                sum = 0, block++;
            sum += a[i];
        }

        if(block > k) {
            low = mid + 1;
        } else {
            high = mid - 1;
            ans = min(ans, mid);
        }
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
