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
    rep(i, 0, n-1) cin >> a[i];

    set<pii> set;
    vector<int> ans(n);
    rrep(i, n-1, 0) {
        auto it = set.lower_bound({a[i]+1, 0});
        //auto it = set.upper_bound({a[i], 1e9});
        if(it != set.end()) {
            while(it != set.end()) {
                ans[(*it).second] = i+1;  
                auto tmp = it;
                ++it;
                set.erase(tmp);
            }
        }
        set.insert({a[i], i});
    }

    rep(i, 0, n-1) cout << ans[i] << " ";
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
