class Solution {
public:
    int mod = 1e9+7;
   
    int numWays(vector<string>& words, string target) {
        int n = target.length();
        int k = words[0].size();
        //freq tabel
        vector<vector<long long>>freq(26,vector<long long>(k+1,0));
        for(int col =0;col <k;col++){
            for(string &word : words){
                char ch = word[col];
                freq[ch-'a'][col]++;
            }
        }
        vector<vector<long long>>dp(n+1,vector<long long>(k+1,0));
        for(int j=0;j<=k;j++)dp[n][j] =1;
        for(int i=0;i<n;i++) dp[i][k]=0;

        for(int i=n-1;i>=0;i--){
            for(int j=k-1;j>=0;j--){
                long long not_take = dp[i][j+1];
                long long  take = (freq[target[i]-'a'][j]*dp[i+1][j+1])%mod;

                dp[i][j] = (take+not_take)%mod;
            }
        }
        return dp[0][0] ;
    }
};