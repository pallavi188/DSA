class Solution {
public:
    int f(int idx,vector<int>&nums,int jump,vector<vector<int>>&dp){
        int n = nums.size();
        if(idx>=n-1)return jump;
        if(dp[idx][jump] != -1) return dp[idx][jump];

        int mini = INT_MAX;
        for(int i =1;i<=nums[idx];i++){
            mini = min(mini , f(idx+i,nums,jump+1,dp));
        }
        return dp[idx][jump] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
       // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return f(0,nums,0,dp);

        int jump =0,l=0,r = 0;
        while(r<n-1){
            int farthest = 0;
            for(int i=l;i<=r;i++){
                farthest = max(farthest,i+nums[i]);
            }
            l= r+1;
            r = farthest;
            jump = jump+1;
        }
        return jump;
    }
};