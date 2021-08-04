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
            rep(i, 0, n-1) cout << 0 << " ";
        else if(k == 2)
            rep(i, 1, n-1) cout << abs(a[i-1] - a[i]) << " ";
        return;
    } 

    set<pii> left, right;
    ll left_sum = 0, right_sum = 0;
    rep(i, 0, k-1) {
        left_sum += a[i];
        left.insert({a[i], i});
    }

    while(left.size() > k/2 + k%2) {
        pii it = *left.rbegin();
        left.erase(it);
        left_sum -= it.first;
        right.insert(it);
        right_sum += it.first;
    }

    ll mid = left.rbegin()->first;
    cout << mid*left.size() - left_sum + right_sum - mid*right.size() << " "; 

    rep(i, 1, n-k) {
        pii remove = {a[i-1], i-1};
        if(left.count(remove)) {
            left.erase(remove);
            left_sum -= remove.first;
        } else {
            right.erase(remove);
            right_sum -= remove.first;
        }

        if(left.rbegin()->first < a[i+k-1]) {
            right_sum += a[i+k-1];
            right.insert({a[i+k-1], i+k-1});
        } else {
            left_sum += a[i+k-1];
            left.insert({a[i+k-1], i+k-1});
        }

        while(left.size() < k/2 + k%2) {
            pii it = *right.begin();
            right.erase(it);
            right_sum -= it.first;
            left.insert(it);
            left_sum += it.first;
        }

        while(left.size() > k/2 + k%2) {
            pii it = *left.rbegin();
            left.erase(it);
            left_sum -= it.first;
            right.insert(it);
            right_sum += it.first;
        }

        ll mid = left.rbegin()->first;
        cout << mid*left.size() - left_sum + right_sum - mid*right.size() << " "; 
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
