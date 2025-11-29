class Solution {
public:
    bool f(string s,int idx,int cnt,vector<vector<int>>&dp){
        int n = s.length();
        if(cnt<0)return false;
        if(idx == n){
            return (cnt==0);
        }
        if(dp[idx][cnt] != -1) return dp[idx][cnt];

        if(s[idx]=='(') return dp[idx][cnt] =  f(s,idx+1,cnt+1,dp);
        else if(s[idx]==')') return dp[idx][cnt] = f(s,idx+1,cnt-1,dp);
        else{
            return dp[idx][cnt] =  f(s,idx+1,cnt+1,dp) | f(s,idx+1,cnt-1,dp) | f(s,idx+1,cnt,dp);
        }
    }
    bool checkValidString(string s) {
        int cnt =0;
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(s,0,0,dp);
    }
};