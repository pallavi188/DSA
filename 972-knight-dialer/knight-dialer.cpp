class Solution {
public:
    int mod = 1e9+7;
    //adjList
    vector<vector<int>>adj = {
         {4,6},
         {6,8},
         {7,9},
         {4,8},
         {0,3,9},
         {},
         {1,7,0},
         {2,6},
         {1,3},
         {2,4}
    };
   
    int knightDialer(int n) {
        
        vector<vector<int>>dp(n+1,vector<int>(10,0));
        for(int cell=0;cell<=9;cell++) dp[0][cell] = 1;
        for(int N = 1;N<n;N++){
            for(int cell=0;cell<=9;cell++){
                int ans = 0;
                for(int &nextCell : adj[cell]){
                    ans = (ans + dp[N-1][nextCell])%mod;
                }
                dp[N][cell] = ans;
        }
        }
        int res = 0;
        for(int cell=0;cell<=9;cell++){
            res = (res + dp[n-1][cell])%mod;
        }
        return res;
    }
};