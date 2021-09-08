#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
void solve_problem() {
    int n, k;
    cin >> n >> k;

    vector<int> vect(n);
    for(int i = 0; i < n; i++) {
        char ch;
        for(int j = 0; j < k; j++) {
            cin >> ch;
            vect[i] += (ch == '1') ? (1 << (k-j-1)) : 0;
        }
    }

    int ans = 32;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++)
            ans = min(ans, __builtin_popcount(vect[i]^vect[j]));
    }

    cout << ans << endl;
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
