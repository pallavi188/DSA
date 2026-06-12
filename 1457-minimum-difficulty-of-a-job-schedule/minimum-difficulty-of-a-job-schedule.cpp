class Solution {
public:
    int f(int idx,int d,vector<int>& jobD,vector<vector<int>>&dp){
        int n = jobD.size();
        if(d == 1){
            int maxD = jobD[idx];
            for(int i=idx;i<n;i++){
                maxD = max(maxD,jobD[i]);
            }
            return maxD;
        }
        if(dp[idx][d] != -1) return dp[idx][d];
        int maxD = jobD[idx];
        int finalResult = INT_MAX;
        for(int i=idx;i<=n-d;i++){
            maxD = max(maxD,jobD[i]);
            int result = maxD + f(i+1,d-1,jobD,dp);
            finalResult = min(finalResult,result);
        }
        return dp[idx][d] = finalResult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d>n) return -1;
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        return f(0,d,jobDifficulty,dp);
    }
};