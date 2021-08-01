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

    vector<int> a(n);
    rep(i, 0, n-1) cin >> a[i];

    ll ans = 0;
    map<int, int> mp;
    int l = 0, r = 0;
    while(l < n) {
        while(r < n && (mp.size() < k || mp.count(a[r]) > 0)) 
            mp[a[r++]]++;
        
        ans += r-l;
        mp[a[l]]--;
        if(mp[a[l]] == 0)
            mp.erase(a[l]);
        l++;
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
