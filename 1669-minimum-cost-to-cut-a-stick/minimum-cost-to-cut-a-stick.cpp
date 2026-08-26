class Solution {
public:
    int f(int l,int r,vector<int>&cuts,vector<vector<int>>&dp){
        if(r-l<=1)return 0;
        int res = 1e9;
        if(dp[l][r] != -1) return dp[l][r];
        for(int i=l+1;i<=r-1;i++){
            int cost = cuts[r] - cuts[l] + f(l,i,cuts,dp) + f(i,r,cuts,dp);
            res = min(res,cost);
        }
        return dp[l][r] = res;
    }
    int minCost(int n, vector<int>& cuts) {
       cuts.push_back(0);
       cuts.push_back(n);
       sort(cuts.begin(),cuts.end());
       sort(cuts.begin(),cuts.end());
       int m = cuts.size();
       vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       return f(0,m-1,cuts,dp);
    }
};