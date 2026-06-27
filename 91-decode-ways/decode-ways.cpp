class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n+1,0);
        dp[n] = 1;
        
        for(int idx=n-1;idx>=0;idx--){
            if(s[idx]=='0'){
                dp[idx] =0;
                continue;
            }
            int one_pick = dp[idx+1];
            int two_pick =0;
            if(idx+1<n){
                if(s[idx] == '1' || s[idx] == '2' && s[idx+1] <= '6')
                two_pick = dp[idx+2];
            }
            dp[idx] = one_pick + two_pick;
        }
        return dp[0];
    }
};