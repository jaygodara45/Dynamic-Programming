#include <bits/stdc++.h>
using namespace std;

int n,w;
vector<int> wi, vi;
int dp[21][101];

int rec(int i, int cur_weight){
    // pruning
    if(cur_weight>w) return INT_MIN;
    
    // base case 
    if(i==n){
        if(cur_weight<=w) return 0;
        else return INT_MIN;
    }
    
    // caching
    if(dp[i][cur_weight]!=-1) return dp[i][cur_weight];
    
    // choices
    int ans=0;
    
    ans = max(rec(i+1, cur_weight), rec(i+1, cur_weight+wi[i])+vi[i]);
    
    // return 
    return dp[i][cur_weight] = ans;
    
    
}


int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    // taking input of total number of items and weight capacity
    cin>>n>>w;
    wi.resize(n);
    vi.resize(n);
    
    // taking input weight array 
    for (int i=0;i<n;i++){
        cin>>wi[i]>>vi[i];
    }
    memset(dp, -1, sizeof(dp));
    
    cout<<rec(0,0);
    
    
    
    

    return 0;
}