class Solution {
public:
    int f(int idx1 , int idx2,string text1,string text2,vector<vector<int>>&dp){
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2] != -1)return dp[idx1][idx2];
        if(text1[idx1] == text2[idx2])
         return dp[idx1][idx2] = 1 + f(idx1-1,idx2-1,text1,text2,dp);
        
        return dp[idx1][idx2] = max(f(idx1-1,idx2,text1,text2,dp),f(idx1,idx2-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<m;j++)dp[0][j] =0;
        for(int i =0;i<n;i++)dp[i][0] = 0;

        for(int idx1 =1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(text1[idx1-1]==text2[idx2-1]){
                    dp[idx1][idx2] = 1+ dp[idx1-1][idx2-1];
                }
                else 
                dp[idx1][idx2] = max(dp[idx1-1][idx2] , dp[idx1][idx2-1]);
            }
        }
        return dp[n][m];
    }
};