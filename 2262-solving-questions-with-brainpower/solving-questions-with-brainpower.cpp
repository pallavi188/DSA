class Solution {
public:
    long long f(int idx,vector<vector<int>>& questions,vector<long long>&dp){
        int n = questions.size();
        if(idx>=n) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long solve = questions[idx][0] + f(idx+1+questions[idx][1],questions,dp);
        long long skip = f(idx+1,questions,dp);
        return dp[idx]= max(solve,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n+1,-1);
        return f(0,questions,dp);
    }
};