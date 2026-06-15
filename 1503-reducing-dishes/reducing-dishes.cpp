class Solution {
public:
    
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        sort(sat.begin(),sat.end());
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        for(int idx=n-1;idx>=0;idx--){
            for(int time=1;time<=n;time++){
                int take = time*sat[idx] + dp[idx+1][time+1];
                int not_take = dp[idx+1][time];
                dp[idx][time] = max(take,not_take);
            }
        }
        return dp[0][1];
    }
};