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
    int n, m;
    cin >> n >> m;

    multiset<int> set;
    rep(i, 1, n) {
        int x;
        cin >> x;
        set.insert(x);
    }

    while(m--) {
        int x;
        cin >> x;

        if(set.empty()) {
            cout << -1 << endl;
            continue;
        }

        auto it = set.lower_bound(x);
        if(it == set.begin() && *it > x) {
            cout << -1 << endl;
        } else {
            if(it == set.end() || *it > x) --it;
            cout << *it << endl;
            set.erase(it);
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
