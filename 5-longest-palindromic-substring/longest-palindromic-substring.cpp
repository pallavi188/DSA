class Solution {
public:
     bool f(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>=j) return true;
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = f(i+1,j-1,s,dp);
        
        return dp[i][j] = false;
     }
     string longestPalindrome(string s){
        int n = s.length();
        int maxLen =0;
        int startPoint =0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(f(i,j,s,dp) == true){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        startPoint = i;
                    }
                }
            }
        }
        return s.substr(startPoint,maxLen);
     }
};