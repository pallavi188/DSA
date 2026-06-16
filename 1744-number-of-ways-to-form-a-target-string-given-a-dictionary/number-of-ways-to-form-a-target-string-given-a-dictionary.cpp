class Solution {
public:
    int mod = 1e9+7;
    int f(int i,int j,vector<string>& words, string& target,
    vector<vector<long long>>& freq,vector<vector<long long>>& dp){
         int n = target.length();
        int k = words[0].size();
        if(i == n) return 1;
        if(j == k) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        long long not_taken = f(i,j+1,words,target,freq,dp)%mod;
        long long taken = (freq[target[i]-'a'][j] *
        f(i+1,j+1,words,target,freq,dp))%mod;
        return dp[i][j]= (taken + not_taken)%mod;
    }
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
        vector<vector<long long>>dp(n+1,vector<long long>(k+1,-1));
        return f(0,0,words,target,freq,dp);
    }
};