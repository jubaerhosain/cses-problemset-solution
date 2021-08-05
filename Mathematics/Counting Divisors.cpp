#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//not for interactive
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef pair<int, int> pii;

/*****User defined function*****/
int mod = 1e9+7;
const int N = 1e6+5;
int divisor_freq[N];

void solve() {
    rep(i, 1, N-1) {
        for(int j = i; j < N; j += i)
            divisor_freq[j]++;
    }

    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        cout << divisor_freq[x] << endl;
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
