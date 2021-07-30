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
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    rep(i, 0, n-1) cin >> a[i];

    map<int, pii> mp;
    rep(i, 0, n-1) {
        rep(j, i+1, n-1) {
            int target = x - (a[i] + a[j]);
            if(mp.find(target) != mp.end()) {
                cout << mp[target].first << " " << mp[target].second
                << " " << i+1 << " " << j+1 << endl;
                return; 
            }
        }

        rep(j, 0, i-1) mp[a[i] + a[j]] = {i+1, j+1};
    }

    cout << "IMPOSSIBLE" << endl;
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
