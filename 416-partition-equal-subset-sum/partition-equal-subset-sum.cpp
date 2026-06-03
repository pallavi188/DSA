class Solution {
public:
    bool f(int idx,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target == 0) return true;
        if(idx == 0) return (nums[0]==target);
        
        if(dp[idx][target] != -1) return dp[idx][target];

        int not_pick = f(idx-1,target,nums,dp);
        int pick = false;
        if(nums[idx] <= target){
            pick = f(idx-1,target-nums[idx],nums,dp);
        }
        return dp[idx][target] = (pick|not_pick);
    }
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
       vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
       return f(n-1,target,nums,dp);
    }
};