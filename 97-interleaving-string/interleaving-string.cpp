class Solution {
public:
int n,m,N;
    bool f(int i,int j,int k, string &s1,string &s2,string &s3,vector<vector<vector<int>>>&dp){
        if(i==n && j==m && k==N)return true;
        if(k>=N)return false;
        bool result = false;
        if(dp[i][j][k] != -1)return  dp[i][j][k];
        if(s1[i]==s3[k]){
            result = f(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(result == true) return dp[i][j][k] = true;
        if(s2[j] == s3[k]){
            result = f(i,j+1,k+1,s1,s2,s3,dp);
        }
        return dp[i][j][k] =  result;
    }
    bool isInterleave(string s1, string s2, string s3) {
         n = s1.length();
         m = s2.length();
         N = s3.length();
         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(N+1,-1)));
        if(N > n+m || N < m+n)return false;
        return f(0,0,0,s1,s2,s3,dp);
    }
};