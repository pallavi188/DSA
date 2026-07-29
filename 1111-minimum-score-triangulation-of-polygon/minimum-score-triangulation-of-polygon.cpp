class Solution {
public:
    int f(vector<int>&values,int i,int j,vector<vector<int>>&dp){
        int result = INT_MAX;
        if(j-i < 2)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        for(int k=i+1;k<j;k++){
            int score = values[i]*values[j]*values[k] + f(values,i,k,dp) + f(values,k,j,dp);

            result = min(result , score);
        }
        return dp[i][j] = result;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(values,0,n-1,dp);
    }
};