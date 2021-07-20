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
vector<int> h(N);
vector<int> tree(4*N);
 
int buildST(int i, int l, int r) {
    if(l == r) 
        return tree[i] = h[l];
    
    int mid = (l + r) / 2;
    return tree[i] = max(buildST(2*i+1, l, mid), buildST(2*i+2, mid+1, r));
}
 
void update(int i, int sl, int sr,  int val) {
    if(sl == sr) {                         //update in the leaf node of the tree
        tree[i] -= val;
        cout << sl + 1 << " ";
        return;
    }
    
    int mid = (sl + sr) / 2;
    if(tree[2*i+1] >= val) 
        update(2*i+1, sl, mid, val);
    else 
        update(2*i+2, mid+1, sr, val);
    
    tree[i] = max(tree[2*i+1], tree[2*i+2]); //update intermediate nodes after returning the value of the leaf node
}
 
void update(int val, int n) {
    update(0, 0, n-1, val);
}
 
 
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    rep(i, 0, n-1) cin >> h[i];
 
    //preprocess ST
    buildST(0, 0, n-1);
 
    while(m--) {
        int x;
        cin >> x;
        if(tree[0] < x)
            cout << 0 << " ";
        else    
            update(x, n);
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
