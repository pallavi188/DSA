class Solution {
public:
    int f(int i,int j,vector<int>& nums,vector<vector<int>>&dp){
        int n = nums.size();
        if(i > j) return 0;
        if(i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        int take_i = nums[i] + min(f(i+2,j,nums,dp),f(i+1,j-1,nums,dp));
        int take_j = nums[j] + min(f(i+1,j-1,nums,dp),f(i,j-2,nums,dp));
        return dp[i][j] = max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int score1 = f(0,n-1,nums,dp);
        int sum =0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        int score2 = sum - score1;
        return (score1>=score2);
    }
};