#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef pair<int, int> pii; 
typedef vector<vector<int>> vii;

/*****User defined function*****/
const int N = 2e5+5;

void solve() {
    int n;
    cin >> n;

    vector<pair<pii, int>> ranges;
    rep(i, 0, n-1) {
        int l, r;
        cin >> l >> r;
        ranges.push_back({{l, r}, i});
    }

    sort(all(ranges));

    int time = 0;
    vector<int> ans(n);
    priority_queue<pii> pq;
    for(auto it: ranges) {
        if(pq.empty()) {
            time++;
            ans[it.second] = time;
            pq.push({-it.first.second, ans[it.second]});
        } else {
            pii mn = pq.top();
            if(-mn.first < it.first.first) {
                pq.pop();
                ans[it.second] = mn.second;
                pq.push({-it.first.second, ans[it.second]});
            } else {
                time++;
                ans[it.second] = time;
                pq.push({-it.first.second, ans[it.second]});
            }
        }
    }

    cout << time << endl;
    for(int room: ans) cout << room << " ";
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
