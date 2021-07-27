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

/*****User defined function*****/
const int N = 2e5+5;

void solve() {
    int x, n;
    cin >> x >> n;

    set<int> pos;
    multiset<int> diff;
    pos.insert(0);
    pos.insert(x);
    diff.insert(x);
    rep(i, 1, n) {
        int p;
        cin >> p;
        auto it1 = pos.upper_bound(p);
        auto it2 = it1; it2--;
        pos.insert(p);
        //diff.erase(*it1 - *it2); deletes all duplicates
        diff.erase(diff.find(*it1 - *it2));
        diff.insert(p - *it2);
        diff.insert(*it1 - p);
        print(*(--diff.end()));
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
