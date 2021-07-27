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
    int n;
    cin >> n;

    vector<int> v;
    rep(i, 1, n) 
        v.push_back(i);

    vector<int> ans;
    while(v.size() > 1) {
        vector<int> tmp;
        rep(i, 0, v.size()-1) {
            if(i&1)
                ans.push_back(v[i]);
            else 
                tmp.push_back(v[i]);
        }

        if(v.size()%2 == 0) {
            v = tmp;
        } else {
            int last = tmp.back();
            tmp.pop_back();
            v.clear();
            v.push_back(last);
            for(int i: tmp)
                v.push_back(i);
        }
    } 

    ans.push_back(v[0]);
    for(int i: ans) 
        cout << i << " ";
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
