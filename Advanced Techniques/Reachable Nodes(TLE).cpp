#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
const int N = 5e4+5;
vector<int> g[N], dag[N];
int in[N], low[N], scc[N], indegree[N];
stack<int> stk;
bool used[N], on_stack[N];
int scc_cnt = 0, timer = 0;
ll values[N], dag_values[N];

//each scc is a node in DAG
//scc using tarjan's algorithm
void find_scc(int u) {
    stk.push(u);
    in[u] = low[u] = ++timer;
    used[u] = on_stack[u] = true;

    for(int v: g[u]) {
        if(used[v] && on_stack[v]) {
            low[u] = min(low[u], in[v]);
        } 
        else if(!used[v]) {
            find_scc(v);
            if(on_stack[v]) 
                low[u] = min(low[u], low[v]);
        }
    }

    if(in[u] == low[u]) {
        ++scc_cnt;
        while(!stk.empty()) {
            int v = stk.top();
            stk.pop();
            on_stack[v] = false;
            scc[v] = scc_cnt;
            if(v == u) break;
        }
    }
}

void make_dag(int u) {
    used[u] = true;

    for(int v: g[u]) {
        if(!used[u])
            make_dag(v);
        if(scc[u] != scc[v]) {
            dag[scc[u]].push_back(scc[v]);
            indegree[scc[v]]++;
        }
    }
}

int find_reachable(int u, int p) {
    used[u] = true;
    int cnt = values[u];

    for(int v: dag[u]) {
        if(v == p || used[v])
            continue;
        cnt += find_reachable(v, u);
    }

    return cnt;
}

void solve_problem() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    //find scc
    memset(used, 0, sizeof used);
    for(int u = 1; u <= n; u++) {
        if(!used[u])
            find_scc(u);
    }

    //make dag
    memset(used, 0, sizeof used);
    for(int u = 1; u <= n; u++) {
        if(!used[u])
            make_dag(u);
    }

    for(int u = 1; u <= n; u++) {
        values[scc[u]]++;
    }

    // for(int i = 1; i <= scc_cnt; i++)
    //     cout << values[i] << " ";
    // cout << endl;

    //find reachable
    for(int i = 1; i <= scc_cnt; i++) {
//         for(int u = 1; u <= scc_cnt; u++) 
//             used[u] = false;
        //visited = bitset<50005>(0);
        visited = visited & (~visited);
        dag_values[i] = find_reachable(i, -1);
    }

    for(int i = 1; i <= n; i++) 
        cout << dag_values[scc[i]] << " ";
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
