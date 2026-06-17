class Solution {
public:
   
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n+1,0);
        for(int idx=n-1;idx>=0;idx--){
            int next = idx+1+questions[idx][1];
            long long solve = questions[idx][0];
            if(next <= n)
            solve += dp[next];
            long long skip = dp[idx+1];
            dp[idx] = max(skip,solve);
        }
        return dp[0];
    }
};