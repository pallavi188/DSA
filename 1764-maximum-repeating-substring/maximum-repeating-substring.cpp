class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n=sequence.length();
        int m = word.length();
        vector<int>dp(n,0);

        int max_k = 0;
        for(int i=m-1;i<n;i++){
            if(sequence.substr(i-m+1 , m) == word){
                if(i>=m){
                    dp[i] = dp[i-m] + 1;
                }else{
                    dp[i] = 1;
                }
                    max_k = max(max_k,dp[i]);
            }

        }
        return max_k;
    }
};