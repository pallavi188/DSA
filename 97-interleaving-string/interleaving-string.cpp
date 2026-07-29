class Solution {
public:
int n,m,N;
    bool f(int i,int j, string &s1,string &s2,string &s3,vector<vector<int>>&dp){
        if(i==n && j==m && i+j==N)return true;
        if(i+j>=N)return false;
        bool result = false;
        if(dp[i][j] != -1)return  dp[i][j];
        if(s1[i]==s3[i+j]){
            result = f(i+1,j,s1,s2,s3,dp);
        }
        if(result == true) return dp[i][j] = true;
        if(s2[j] == s3[i+j]){
            result = f(i,j+1,s1,s2,s3,dp);
        }
        return dp[i][j] =  result;
    }
    bool isInterleave(string s1, string s2, string s3) {
         n = s1.length();
         m = s2.length();
         N = s3.length();
         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        if(N > n+m || N < m+n)return false;
        return f(0,0,s1,s2,s3,dp);
    }
};