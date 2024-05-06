#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
int dp[110][100100];

int rec(int level, int sum_rem, vector<int> &arr, vector<int> &queries){
    // pruning
    if(sum_rem<0) return 0;
    // base Case
    if(level==arr.size()){
        if(sum_rem==0) return 1;
        else return 0;
    }
    // caching
    if(dp[level][sum_rem]!=-1) return dp[level][sum_rem];
    // choices explore
    int ans = rec(level+1, sum_rem, arr, queries) || rec(level+1, sum_rem-arr[level], arr, queries);
    
    // save and return
    return dp[level][sum_rem] = ans;
}

void ind(int level, int sum_rem, vector<int> &arr, vector<int> &queries, vector<int> &temp){
    // pruning 
    if(sum_rem<0) return;
    
    // base case 
    if(level==arr.size()){
        return;
    }
    
    // chocies
    if(rec(level+1, sum_rem, arr, queries)){
        ind(level+1, sum_rem,arr,queries,temp);
    }
    else if(rec(level+1, sum_rem-arr[level],arr,queries)) {
        temp.push_back(level);
        ind(level+1, sum_rem-arr[level],arr,queries,temp);
        
    }
    
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
    int n = arr.size();
    int q = queries.size();
    vector<vector<int>> ans;
    
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<q;i++){
        if(rec(0, queries[i], arr, queries)){
            vector<int> temp;
            ind(0, queries[i], arr, queries, temp);
            ans.push_back(temp);
        }
        else{
            vector<int> temp;
            temp.push_back(-1);
            ans.push_back(temp);
        }
    }
    
    return ans;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
