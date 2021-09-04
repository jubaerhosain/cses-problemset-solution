#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
vector<int> z_function(string &text) {
    int n = text.size();

    int left = 0, right = 0;
    vector<int> z_array(n, 0);
    for(int i = 1; i < n; i++) {
        if(i > right) {
            left = i, right = i;
            while(right < n && text[right-left] == text[right])
                right++;
            right--;
            z_array[i] = right - left + 1;
        } 
        else {
            int j = i - left;
            if(z_array[j] < right - i + 1) {
                z_array[i] = z_array[j];
            } 
            else {
                left = i;
                while(right < n && text[right-left] == text[right])
                    right++;
                right--;
                z_array[i] = right - left + 1;
            }
        }
    }
        
    return z_array;
}

vector<int> pi_function(string &text) {
    int n = text.size();

    int len = 0, i = 1;
    vector<int> lps(n, 0);
    while(i < n) {
        if(text[i] == text[len]) {
            lps[i++] = ++len;
        } 
        else {
            if(len != 0)
                len = lps[len-1];
            else
                lps[i++] = 0;
        }
    }

    return lps;
}

void solve_problem() {
    string text;
    cin >> text;

    vector<int> z = z_function(text);
    vector<int> pi = pi_function(text);

    for(int val: z)
        cout << val << " ";
    
    cout << endl;

    for(int val: pi)
        cout << val << " ";
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
