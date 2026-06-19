class Solution {
public:
int mod = 1e9+7;
    int f(int idx,int fuel,int finish,vector<int>&location,vector<vector<long long>>&dp){
        int n = location.size();
        long long ans =0;
        if(fuel<0)return 0;
        if(dp[idx][fuel] != -1) return dp[idx][fuel];
        if(idx == finish) ans = 1;
        for(int i=0;i<n;i++){
            if(i != idx){
                ans = (ans + f(i,fuel-abs(location[i] - location[idx]),finish,location,dp))%mod;
            }
        }
        return dp[idx][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<long long>>dp(n+1,vector<long long>(fuel+1,-1));
        return f(start,fuel,finish,locations,dp);
    }
};