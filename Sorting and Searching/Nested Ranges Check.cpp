#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef pair<int, int> pii; 
typedef vector<vector<int>> vii;

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

    //[[l, r], i]
    vector<pair<pii, int>> ranges;
    vector<bool> contains(n), contained(n);
    rep(i, 0, n-1) {
        int l, r;
        cin >> l >> r;
        ranges.push_back({{l, r}, i});
    }

    sort(all(ranges), cmp);

    int min_right = 1e9+5;
    rrep(i, n-1, 0) {
        if(ranges[i].first.second >= min_right)
            contains[ranges[i].second] = true;
        min_right = min(min_right, ranges[i].first.second);
    }

    int max_right = 0;
    rep(i, 0, n-1) {
        if(ranges[i].first.second <= max_right) 
            contained[ranges[i].second] = true;
        max_right = max(max_right, ranges[i].first.second);
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
} v
