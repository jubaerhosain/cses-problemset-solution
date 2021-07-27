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
int pos[N];

void solve() {
    int n;
    cin >> n;

    multiset<int> set;
    rep(i, 0, n-1) {
        int x;
        cin >> x;
        auto it = set.upper_bound(x);
        if(it == set.end()) 
            set.insert(x);
        else 
            set.erase(it), set.insert(x);
    }

    print(set.size());
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
