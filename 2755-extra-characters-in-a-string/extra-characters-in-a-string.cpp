class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
       unordered_set<string>st;
       int n = s.length();
       vector<int>dp(n+1,0);
       for(string &word : dictionary){
        st.insert(word);
       }
     
       
        for(int idx = n-1;idx>=0;idx--){
            string currStr = "";
            int minExtra = 1+dp[idx+1];
            for(int i=idx;i<n;i++){
            currStr.push_back(s[i]);
            int currExtra = (st.find(currStr) == st.end()) ? currStr.length():0;
            int remainingExtra =dp[i+1];
            minExtra = min(minExtra,currExtra + remainingExtra);

        }
        dp[idx] = minExtra;
        }
        return dp[0];
    }
};