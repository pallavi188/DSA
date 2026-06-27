class Solution {
public:
    int f(int idx,string s,vector<int>&dp){
        int n = s.length();
        if(idx == n) return 1;
        if(s[idx] == '0') return 0;
         if(dp[idx] != -1) return dp[idx];
        int one_pick = f(idx + 1,s,dp);
        int two_pick = 0;
        if(idx+1 < n){
        if(s[idx] == '1' || s[idx] == '2' && s[idx+1]<='6')
        two_pick = f(idx+2,s,dp);
        }
        return dp[idx] = one_pick + two_pick;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n+1,-1);
        return f(0,s,dp);
    }
};