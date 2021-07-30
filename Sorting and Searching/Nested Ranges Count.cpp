#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef pair<int, int> pii; 
typedef vector<vector<int>> vii;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, 
less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*****User defined function*****/
const int N = 2e5+5;

bool cmp(pair<pii, int> a, pair<pii, int> b) {
    if(a.first.first == b.first.first) 
        return a.first.second > b.first.second; //if l is equal then decreasing by r
    else 
        return a.first.first < b.first.first;
}

void solve() {
    int n;
    cin >> n;

    ordered_set<pii> set;
    vector<pair<pii, int>> ranges;
    vector<int> contains(n), contained(n);
    rep(i, 0, n-1) {
        int l, r;
        cin >> l >> r;
        ranges.push_back({{l, r}, i});
    }

    sort(all(ranges), cmp);

    //all ranges inside the current 
    //range are the below of this range 
    rrep(i, n-1, 0) {
        pii key = {ranges[i].first.second, -i};
        set.insert(key);
        contains[ranges[i].second] = set.order_of_key(key);
    }

    //all ranges contains current 
    //range are int the top of this range
    set.clear();
    rep(i, 0, n-1) {
        pii key = {ranges[i].first.second, -i};
        set.insert(key);
        contained[ranges[i].second] = set.size() - set.order_of_key(key) - 1;
    }

    rep(i, 0, n-1) cout << contains[i] << " ";
    cout << endl;
    rep(i, 0, n-1) cout << contained[i] << " ";
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
