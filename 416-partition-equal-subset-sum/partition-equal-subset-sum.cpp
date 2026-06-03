class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
       int n = nums.size();
       int sum = 0,target =0;
       for(int i=0;i<n;i++){
        sum += nums[i];
       }
       if(sum%2 != 0) return false;
       else{
        target = sum/2;
       }
       vector<vector<int>>dp(n+1,vector<int>(target+1,0));
       for(int i=0;i<n;i++)dp[i][0] = true;
       if(nums[0] <= target)
       dp[0][nums[0]] = true;

       for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool not_pick = dp[i-1][j];
            bool pick = false;
            if(nums[i] <= j){
                pick = dp[i-1][j-nums[i]];
            }
            dp[i][j] = (pick || not_pick);
        }
       }
       return dp[n-1][target];
    }
};