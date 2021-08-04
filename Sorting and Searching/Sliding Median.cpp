#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//not for interactive
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef pair<int, int> pii;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, 
less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
/*****User defined function*****/
const int N = 2e5+5;
 
void solve() {
    int n , k;
    cin >> n >> k;
 
    int mx = 0;
    vector<int> a(n);
    rep(i, 0, n-1) cin >> a[i]; 
 
    ordered_set<pii> set;
    rep(i, 0, k-1) set.insert({a[i], i});
    rep(i, 0, n-k) {
        cout << set.find_by_order((k-1)/2)->first << " ";
        if(i < n - k) {
            set.erase({a[i], i});
            set.insert({a[i+k], i+k});
        }
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
