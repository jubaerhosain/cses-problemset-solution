#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

//make faster bitwise operation
#pragma GCC target("popcnt")

 
/*****User defined function*****/
void solve_problem() {
    int n;
    cin >> n;

    vector<bitset<3000>> bst(n);
    for(int i = 0; i < n; i++) {
        string bstr;
        cin >> bstr;
        bst[i] = bitset<3000>(bstr);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            ll count = (bst[i] & bst[j]).count();
            ans += (count * (count-1)) / 2;
        }
    }

    cout << ans;
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
    while(test--) solve_problem();
 
    return 0;
} 
