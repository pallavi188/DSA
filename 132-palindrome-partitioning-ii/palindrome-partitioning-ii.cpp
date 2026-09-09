class Solution {
public:
    bool isPalin(int i,int j,string &s){
      
       
        while(i<j){
        if(s[i] != s[j]) return false;
        else{
            i++;
            j--;
        }
        }
        return true;
    }
    int f(int i,string &s,vector<int>&dp){
        int n = s.length();
        if(i == n)return 0; 
        int minCost = INT_MAX;
        if(dp[i] != -1)return dp[i];
        for(int j=i;j<n;j++){
           
            if(isPalin(i,j,s)){
            int cost = 1 + f(j+1,s,dp);
            minCost = min(minCost,cost);
            }
        }
        return dp[i] = minCost;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int minCost = INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalin(i,j,s)){
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost,cost);
                }
                dp[i] = minCost;
            }
        }
        return dp[0]-1;
    }
};