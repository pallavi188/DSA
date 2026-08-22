class Solution {
public:
   
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0;i<n;i++)totalSum += nums[i];
        if(abs(target) > totalSum)return 0;
        if((totalSum+target)%2 != 0)return 0;
        int reqSum = (totalSum + target)/2;
        vector<vector<int>>dp(n+1,vector<int>(reqSum+1,0));
        //base case
         dp[n][0] = 1;

        for(int i=n-1;i>=0;i--){
            for(int rs = 0;rs<=reqSum;rs++){
                int pick = 0;
                if(nums[i] <= rs)
                pick = dp[i+1][rs-nums[i]];
                int not_pick = dp[i+1][rs];
                dp[i][rs] = (pick + not_pick);
            }
        }
        return dp[0][reqSum];
    }
};