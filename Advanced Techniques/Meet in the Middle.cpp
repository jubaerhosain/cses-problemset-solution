#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
void solve_problem() {
    ll n, x;
    cin >> n >> x;

    vector<ll> vect(n);
    for(int i = 0; i < n; i++)
        cin >> vect[i];

    vector<ll> left, right;
    int n1 = n/2, n2 = n - n/2;
    for(int i = 0; i < (1<<n1); i++) {
        ll sum = 0;
        for(int j = 0; j <= 20; j++) {
            if(i & (1<<j))
                sum += vect[j];
        }
        left.push_back(sum);
    }

    for(int i = 0; i < (1<<n2); i++) {
        ll sum = 0;
        for(int j = 0; j <= 20; j++) {
            if(i & (1<<j))
                sum += vect[n1 + j];
        }
        //map[sum]++;  map gives TLE
        right.push_back(sum);
    }
     
    ll count = 0;
    sort(right.begin(), right.end());
    for(ll val: left) {
        count += upper_bound(right.begin(), right.end(), x-val) -
                 lower_bound(right.begin(), right.end(), x-val);
    }

    cout << count << endl;
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
