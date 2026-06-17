class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int>dp(n+1,0);
        dp[n] = 1;
        for(int st=n-1;st>=0;st--){
            if(s[st] == '0'){
                dp[st] = 0;
                continue;
            }
            long long num =0;
            long long ans =0;
            for(int end = st;end<n;end++){
                num = (num*10)+(s[end]-'0');
                if(num >k) break;
                ans = (ans + dp[end+1])%mod;
                
            }
            dp[st] = ans;
        }
        return dp[0];
    }
};