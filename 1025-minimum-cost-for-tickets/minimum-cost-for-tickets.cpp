class Solution {
public:
    int f(int idx,vector<int>&days,vector<int>&costs,vector<int>&dp){
        int n = days.size();
        if(idx >= n) return 0;
         if(dp[idx] != -1) return dp[idx];
        //1 day pass
        int cost_1 = costs[0] + f(idx+1,days,costs,dp);
        //2 day pass
        int j = idx;
        int max_day7 = days[idx] + 7;
        while(j < n && days[j] < max_day7) j++;
        int cost_7 = costs[1] + f(j,days,costs,dp);
        // 30 days pass
        int k = idx;
        int max_day30 = days[idx]+30;
        while(k < n && days[k] < max_day30) k++;
        int cost_30 = costs[2] + f(k,days,costs,dp);
        return dp[idx] = min({cost_1,cost_7,cost_30}); 
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(366,-1);
        return f(0,days,costs,dp);
    }
};