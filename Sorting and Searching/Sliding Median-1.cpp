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
    int n , k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, 0, n-1) cin >> a[i]; 

    if(k == 1 || k == 2) {
        if(k == 1)
            rep(i, 0, n-1) cout << a[i] << " ";
        else if(k == 2)
            rep(i, 1, n-1) cout << min(a[i-1], a[i]) << " ";
        return;
    } 

    set<pii> left, right;
    rep(i, 0, k-1) {
        left.insert({a[i], i});
    }

    while(left.size() > k/2 + k%2) {
        pii it = *left.rbegin();
        left.erase(it);
        right.insert(it);
    }

    cout << left.rbegin()->first << " ";  

    rep(i, 1, n-k) {
        if(left.count({a[i-1], i-1})) 
            left.erase({a[i-1], i-1});
        else 
            right.erase({a[i-1], i-1});
        
        if(left.rbegin()->first < a[i+k-1]) 
            right.insert({a[i+k-1], i+k-1});
        else 
            left.insert({a[i+k-1], i+k-1});

        while(left.size() < k/2 + k%2) {
            pii it = *right.begin();
            right.erase(it);
            left.insert(it);
        }

        while(left.size() > k/2 + k%2) {
            pii it = *left.rbegin();
            left.erase(it);
            right.insert(it);
        }

        cout << left.rbegin()->first << " "; 
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
