class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
       int n =nums.size();
       vector<vector<int>>dp(n+1,vector<int>(n+1,0));
       //base case

       for(int idx=n-1;idx>=0;idx--){
        for(int pI=idx-1;pI>=-1;pI--){
            int len = dp[idx+1][pI + 1];
            if(pI == -1 || nums[idx] > nums[pI])
                len = max(len,1 + dp[idx+1][idx + 1]);
                dp[idx][pI+1] = len;
            
        }
       }
       return dp[0][0];
    }
};