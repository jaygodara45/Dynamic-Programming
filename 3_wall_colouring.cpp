#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[2010][2010];

const int MOD = 1e9+7;
int n,m,k;
int rec(int i, int j, int m){
    // pruning
    if(j>k) return 0;
    // base case 
    if(i==0){
        if(j==0) return m;
        else return 0;
    }
    
    // caching
    if(dp[i][j]!=-1) return dp[i][j];
    // choices
    // same color
    int ans = rec(i-1,j,m);
    ans = (ans + rec(i-1, j-1,m)*(m-1))%MOD;
    
    // return
    return dp[i][j]=ans;
}

void solve(){
    
    cin>>n>>m>>k;
    memset(dp, -1, sizeof(dp));
    
    cout<<rec(n-1,k,m)<<endl;
}

signed main()
{
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}