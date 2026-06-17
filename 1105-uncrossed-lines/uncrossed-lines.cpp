class Solution {
public:
    int f(int idx1,int idx2,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp){
        int n = nums1.size();
        int m = nums2.size();
        if(idx1>=n || idx2>=m) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        int match = 0;
        if(nums1[idx1] == nums2[idx2])
        match = 1 + f(idx1+1,idx2+1,nums1,nums2,dp);
        int not_match = max(f(idx1+1,idx2,nums1,nums2,dp),f(idx1,idx2+1,nums1,nums2,dp));
        return dp[idx1][idx2] = max(match,not_match);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(0,0,nums1,nums2,dp);   
    }
};