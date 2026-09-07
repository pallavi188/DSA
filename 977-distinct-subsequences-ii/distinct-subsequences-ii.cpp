class Solution {
public:
int mod = 1e9+7;
    int solve(int i,string s,vector<int>&prev,vector<long long>&dp){
        int n = s.length();
        if(i==0) return 1;
        if(dp[i] != -1)return dp[i];
        long long total = (2*solve(i-1,s,prev,dp))%mod;
        if(prev[i] != 0){
            long long duplicate = solve(prev[i]-1,s,prev,dp);
            total =(total -  duplicate + mod)%mod;
        }
        return dp[i] =  total;
    }
    int distinctSubseqII(string s) {
        int n = s.length();
        vector<int>prev(n+1,0);
        vector<int>lastSeen(26,0);
        vector<long long>dp(2001,-1);
        for(int i=1;i<=n;i++){
            int idx = s[i-1]-'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }
        return (solve(n,s,prev,dp)-1 + mod)%mod;
    }
};