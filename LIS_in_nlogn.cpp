#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; 
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    vector<int> ans;
    vector<int> lis;
    for(int i=0;i<n;i++){
        if(lis.empty() || lis.back()<arr[i]){
            lis.push_back(arr[i]);
            // if new element is inserted at last, means LIS's size is increased by 1
            ans = lis;
            
        }
        else{
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
        }
        
        // for(auto v:lis) cout<<v<<" ";
        // cout<<endl;
    }
    cout<<lis.size()<<endl;
    cout<<"ans"<<endl;
    for(auto v:ans) cout<<v<<" ";
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
