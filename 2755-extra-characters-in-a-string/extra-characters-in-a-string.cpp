class Solution {
public:
    
    int f(int idx,string s,unordered_set<string>&st,vector<int>&dp){
        int n = s.length();
        if(idx >= n) return 0;
        int minExtra =n;
        string currStr = "";
        if(dp[idx] != -1) return dp[idx];
        for(int i=idx;i<n;i++){
            currStr.push_back(s[i]);
            int currExtra = (st.find(currStr) == st.end()) ? currStr.length():0;
            int remainingExtra =f(i + 1,s,st,dp);
            minExtra = min(minExtra,currExtra + remainingExtra);
        }
        return dp[idx] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
       unordered_set<string>st;
       int n = s.length();
       vector<int>dp(n+1,-1);
       for(string &word : dictionary){
        st.insert(word);
       }
        return f(0,s,st,dp);
    }
};