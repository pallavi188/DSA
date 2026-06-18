class Solution {
public:
    int f(int l,int r,vector<int>&cuts,vector<vector<int>>&dp){
        if(r-l < 2){
            return 0;
        }
        if(dp[l][r] != -1) return dp[l][r];
        int result = 1e9;
        for(int i=l+1;i<=r-1;i++){
            int cost = (cuts[r] - cuts[l]) + f(l,i,cuts,dp) + f(i,r,cuts,dp);
            result =  min(result,cost);
        }
        return dp[l][r] = result;
    }
    int minCost(int n, vector<int>& cuts) {
       
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return f(0,m-1,cuts,dp);
    }
};