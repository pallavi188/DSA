class Solution {
public:
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int idx1=n-1;idx1>=0;idx1--){
            for(int idx2=m-1;idx2>=0;idx2--){
                int match =0;
                if(nums1[idx1] == nums2[idx2])
                match = 1 + dp[idx1+1][idx2+1];
                int not_match = max(dp[idx1+1][idx2],dp[idx1][idx2+1]);

                dp[idx1][idx2] = max(match,not_match);
            }
        }
        return dp[0][0];
    }
};