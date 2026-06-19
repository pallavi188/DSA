class Solution {
public:
    int f(int idx,int diff,vector<int>&rods,vector<vector<int>>&dp){
        int n = rods.size();
        if(idx>=n){
            if(diff == 0) return 0;
            else 
            return -1e9;
        }
        if(dp[idx][diff + 5001] != -1) return dp[idx][diff+5001];
        int op1 =rods[idx] + f(idx+1,diff + rods[idx],rods,dp);
        int op2 =rods[idx] + f(idx+1,diff - rods[idx],rods,dp);
        int op3 = f(idx+1,diff,rods,dp);
        return dp[idx][diff + 5001] = max({op1,op2,op3});
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>>dp(n+1,vector<int>(10003,-1));
        return f(0,0,rods,dp)/2;
    }
};