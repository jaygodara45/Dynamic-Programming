#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; 
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    
    vector<int> lis;
    int insertedAt[n+1];
    for(int i=0;i<n;i++){
        if(lis.empty() || lis.back()<arr[i]){
            lis.push_back(arr[i]);
            
            insertedAt[i] = lis.size();
            
        }
        else{
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
            insertedAt[i] = it - lis.begin() + 1;
        }
        
        // for(auto v:lis) cout<<v<<" ";
        // cout<<endl;
    }
    cout<<lis.size()<<endl;
    
    cout<<"Printing LIS:"<<endl;
    int curLen = lis.size();
    vector<int> lis_final;
    for(int i=n-1;i>=0;i--){
        if(insertedAt[i]==curLen) {
            lis_final.push_back(arr[i]);
            curLen--;
        }
    }
    
    cout<<endl;
    reverse(lis_final.begin(), lis_final.end());
    for(auto v:lis_final) cout<<v<<" ";
    cout<<endl;
}

int main()
{
    int t; 
    // cin>>t;
    t=1;
    while(t--) solve();

    return 0;
}
