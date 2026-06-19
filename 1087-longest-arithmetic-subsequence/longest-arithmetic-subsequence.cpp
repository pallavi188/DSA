class Solution {
public:
    int f(int i,int d,vector<int>&nums,vector<vector<int>>&dp){
        if(i<0)return 0;
        int ans =0;
        if(dp[i][d+501] != -1) return dp[i][d+501];
        for(int k =i-1;k>=0;k--){
            if(nums[i]-nums[k] == d){
                ans = max(ans,1 + f(k,d,nums,dp));
            }
        }
        return dp[i][d+501] = ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int res =0;
        if(n<=2) return n;
        vector<vector<int>>dp(1001,vector<int>(1003,-1));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d = nums[j]-nums[i];
                res = max(res,2 + f(i,d,nums,dp));
            }
        }
        return res;
    }
};