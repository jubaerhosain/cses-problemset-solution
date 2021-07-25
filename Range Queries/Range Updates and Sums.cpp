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
struct Node {
    int flag;
    long long sum;
    long long setAll;
    long long increment;  
};

const int N = 2e5+5;
int a[N];
Node tree[4*N];

ll buildST(int i, int l, int r) {
    if(l == r) 
        return tree[i].sum = a[l];

    int mid = (l + r) / 2;
    return tree[i].sum = buildST(2*i+1, l, mid) + buildST(2*i+2, mid+1, r);
}

void pending_update(int i, int sl, int sr) {
    //if setAll comes first then erase previous data 
    ///and update by current node increment
    //if increment comes first then only incement bcz
    //may have setAll operation of previous time

    if(tree[i].flag)          //update all pending nodes
        tree[i].sum = tree[i].setAll * (sr-sl+1);
    if(tree[i].increment) 
        tree[i].sum += tree[i].increment * (sr-sl+1);
    
    if(sl != sr) {             //update child nodes and reset parent (i)
        int lc = 2*i+1, rc = 2*i+2;

        if(tree[i].flag) {
            tree[lc].flag = tree[rc].flag = 1;
            tree[lc].setAll = tree[rc].setAll = tree[i].setAll;
            tree[lc].increment = tree[rc].increment = tree[i].increment;
        } else if(tree[i].increment) {
            tree[lc].increment += tree[i].increment;
            tree[rc].increment += tree[i].increment;
        }
    }
        
    tree[i].flag = tree[i].setAll = tree[i].increment = 0;
}

ll get_sum(int i, int sl, int sr, int l, int r) {
    pending_update(i, sl, sr);
    
    if(sl >= l && sr <= r)          // total overlap
        return tree[i].sum;
    else if(sr < l || r < sl)       // no overlap;
        return 0;

    int mid = (sl + sr) / 2;
    return get_sum(2*i+1, sl, mid, l, r) + get_sum(2*i+2, mid+1, sr, l, r);
    
}

void range_update(int i, int sl, int sr, int l, int r, int val, int type) {
    pending_update(i, sl, sr);

    if(sr < l || r < sl)       // no overlap;
        return;

    if(sl >= l && sr <= r)  {     // total overlap
        if(type == 1) { 
            tree[i].increment += val;
        } else {
            tree[i].flag = 1;
            tree[i].setAll = val;
            tree[i].increment = 0;
        }

        //pending update for current change
        pending_update(i, sl, sr);
        return;
    }

    int mid = (sl + sr) / 2;
    range_update(2*i+1, sl, mid, l, r, val, type);
    range_update(2*i+2, mid+1, sr, l, r, val, type);
    
    //update intermediate nodes after returning the value of the leaf node
    tree[i].sum = tree[2*i+1].sum + tree[2*i+2].sum;  
}

ll get_sum(int l, int r, int n) {
    return get_sum(0, 0, n-1, l, r);
}

void range_update(int l, int r, int n, int val, int type) {
    range_update(0, 0, n-1, l, r, val, type);
}
 
void solve() {
    int n, q;
    cin >> n >> q;

    rep(i, 0, n-1) cin >> a[i];

    buildST(0, 0, n-1);

    while(q--) {
        int type;
        cin >> type;
        if(type != 3) {
            int l, r, val;
            cin >> l >> r >> val;
            range_update(l-1, r-1, n, val, type);
        } else {
            int l, r;
            cin >> l >> r;
            print(get_sum(l-1, r-1, n));
        }
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
