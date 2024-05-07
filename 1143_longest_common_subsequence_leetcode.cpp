// Problem link: https://leetcode.com/problems/longest-common-subsequence/description/
// Jay Godara
class Solution {
public:
    vector<vector<int>> dp;
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        dp.assign(n1+1, vector<int>(n2+1,0));

        

        for(int i=0;i<n1;i++){
            if(text1[i]==text2[0]) dp[i][0]=1;
        }
        for(int i=0;i<n2;i++){
            if(text1[0]==text2[i]) dp[0][i]=1;
        }
        

        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                
            if(text1[i]==text2[j]){ 
                if(i>0 && j>0) dp[i][j] = 1 + dp[i-1][j-1];
            }
            
                
            if(i>0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j>0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
            
                
            }
        }

        return dp[n1-1][n2-1];
        
    }
};
