class Solution {
public:
    int f(int idx,vector<int>&sv,vector<int>&dp){
       int n = sv.size();
        if(idx>=n) return 0;
        int result = -1e9;
        if(dp[idx] != -1) return dp[idx];
        result = max(result,sv[idx] - f(idx+1,sv,dp));
        if(idx+1<n)
        result = max(result,sv[idx]+sv[idx+1]-f(idx+2,sv,dp));
        if(idx+2<n)
        result = max(result,sv[idx]+sv[idx+1]+sv[idx+2]-f(idx+3,sv,dp));
        return dp[idx]= result;
    }
    string stoneGameIII(vector<int>& sv) {
        int n = sv.size();
        vector<int>dp(n+1,-1);
        int diff = f(0,sv,dp);
        if(diff>0) return "Alice";
        else if(diff<0) return "Bob";
        else
        return "Tie";
    }
};