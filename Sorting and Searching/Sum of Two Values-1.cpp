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
    
    vector<pii> a(n);
    rep(i, 0, n-1) {
        int x;
        cin >> x;
        a[i] = {x, i+1};
    }

    sort(a.begin(), a.end());

    int l = 0, r = n-1;
    while(l < r) {
        if(a[l].first + a[r].first < x) 
            l++;
        else if(a[l].first + a[r].first > x)
            r--;
        else {
            cout << a[l].second << " " << a[r].second << endl;
            return;
        }
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
