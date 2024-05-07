// Problem link: https://leetcode.com/problems/longest-increasing-subsequence/
// Jay Godara (github.com/jaygodara45)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        dp.resize(n+1);

        dp[0]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            int cur_elem = nums[i];
            int max_ans=1;
            for(int j=0;j<i;j++){
                if(nums[j]<cur_elem) max_ans = max(max_ans, dp[j]+1);
            }
            dp[i] = max_ans;
            ans = max(ans, dp[i]);
        }
        return ans;

        
    }
};
