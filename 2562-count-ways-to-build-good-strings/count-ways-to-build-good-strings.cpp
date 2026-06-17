class Solution {
public:
    int mod = 1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,0);
        dp[high] = 1;
        for(int l=high-1;l>=0;l--){
            bool addOne = false;
            if(l>=low) addOne = true;
            int append0 = 0;
            if(l+zero <= high) append0 = dp[l+zero];
            int append1 = 0;
            if(l+one <= high) append1 = dp[l+one];

            dp[l] = (addOne + append0 + append1)%mod;
        }
        return dp[0];
    }
};