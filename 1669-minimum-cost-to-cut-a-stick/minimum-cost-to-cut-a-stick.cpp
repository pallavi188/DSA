class Solution {
public:
    int f(int i,int j,vector<int>& cuts,vector<vector<int>>&dp){
       if(i>j) return 0;
       if(dp[i][j] != -1) return dp[i][j];
       int mini = INT_MAX;
       for(int idx = i;idx<=j;idx++){
        int cost =  ( cuts[j+1] - cuts[i-1] ) + 
        f(i,idx-1,cuts,dp) + 
        f(idx+1,j,cuts,dp);
        mini = min(mini,cost);
       }
       return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+2,vector<int>(c+2,-1));
        return f(1,c,cuts,dp);
    }
};