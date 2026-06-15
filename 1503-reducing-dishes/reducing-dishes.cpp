class Solution {
public:
    int f(int idx,int time,vector<int>&sat,vector<vector<int>>&dp){
        int n = sat.size();
        if(idx == n)return 0;
        if(dp[idx][time] != -1) return dp[idx][time];
        int take = time*sat[idx] + f(idx+1,time+1,sat,dp);
        int not_take = f(idx+1,time,sat,dp);
        return dp[idx][time] = max(take,not_take);
    }
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        sort(sat.begin(),sat.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0,1,sat,dp);
    }
};