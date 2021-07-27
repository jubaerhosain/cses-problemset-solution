#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
template<class T> using ordered_set = tree<T, null_type, 
less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*****User defined function*****/
const int N = 2e5+5;

void solve() {
    int n, k;
    cin >> n >> k;

    ordered_set<int> set;
    rep(i, 1, n) set.insert(i);

    int pos = 0;
    while(set.size() > 0) {
        pos = (pos + k) % set.size();
        auto it = set.find_by_order(pos);
        cout << *it << " ";
        set.erase(it);
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
