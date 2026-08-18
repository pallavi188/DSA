class Solution {
public:
    bool solve(string &s,unordered_set<string>&st,int idx,vector<int>&dp){
        int n = s.length();
        if(idx == n)return true;
        if(dp[idx] != -1)return dp[idx];
        if(st.find(s) != st.end())return true;
        for(int l = 1;l<=n;l++){
            string temp = s.substr(idx,l);
            if(st.find(temp) != st.end() && solve(s,st,idx+l,dp))return true;
        }
        return dp[idx] =  false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int>dp(n+1,-1);
        unordered_set<string>st;
        for(string &s : wordDict){
            st.insert(s);
        }
        return solve(s,st,0,dp);
    }
};