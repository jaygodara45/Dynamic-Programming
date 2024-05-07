/*
  Intuition: Start from top to bottom. Check for above 3 windows which can make current window dirty. Update accordingly.
  Don't think in this way: Which windows can be made dirty by current window because then we will have to explore all multiple windows every time.
  **MOVE FROM TOP TO BOTTOM.
*/
#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1010][1010];
int dp[1010][1010];

void solve(){
    cin>>n>>m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>a[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(i>0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(i>0 && j>0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            if(i>0 && j<m-1) dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
            
            int cleaning_time = a[i][j];
            if(cleaning_time>dp[i][j]) a[i][j]=1;
            else a[i][j]=0;
            dp[i][j] = max(dp[i][j], cleaning_time);
            
            
            
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    
}

int main()
{
    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
