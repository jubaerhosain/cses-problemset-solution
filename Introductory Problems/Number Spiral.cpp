#include<bits/stdc++.h>
using namespace std;
#define all(v)                  v.begin(), v.end()
#define rall(v)                 v.rbegin(), v.rend()
#define des()                   greater<int>()
#define rep(i, a, n)            for(int i = a; i < n; i++)  
#define rrep(i, n, a)           for(int i = n; i >= a; i--)
#define pqueue                  priority_queue
#define umap                    unordered_map
#define uset                    unordered_set
#define pub                     push_back
#define pob                     pop_back  
#define endl                    '\n'    //in interactive problem should not use this
#define println                 cout << endl
#define scan_array(arr, n)      for(int i = 0; i < n; i++) { cin >> arr[i]; }
#define print_array(arr, n)     for(int i = 0; i < n; i++) { cout << arr[i] << " "; } println;
#define print(var)              cout << var << endl
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
const int eps = 1e-9;
const int inf = INT_MAX;
const int N = 2e5+10;

/*************User defined function*************/
void solve() {
    ull x, y;
    cin >> x >> y;

    ull ans = 0;
    if(x > y) {
        if(x%2 == 0) {
            ans = (x*x)-y+1;
        } else {
            x--;
            ans = (x*x)+y;
        }
    } else if(y > x) {
        if(y%2 == 1) {
            ans = (y*y)-x+1;
        } else {
            y--;
            ans = (y*y)+x;
        }
    } else {
        if(x%2 == 0) {
            ans = (x*x)-y+1;
        } else {
            ans = (y*y)-x+1;
        }
    }

    print(ans);
}

/*************main function*************/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    int test;
    cin >> test;
    while(test-- > 0) {
        solve();
    }

    //solve();

    return 0;
}    
