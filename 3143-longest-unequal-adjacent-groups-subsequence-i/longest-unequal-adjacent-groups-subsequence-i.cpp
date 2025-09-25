class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int>dp(n,1);
        vector<int>parent(n,-1);

        int best0=-1,best1=-1;
        for(int i=0;i<n;i++){
            if(groups[i] == 0){
                if(best1 != -1){
                    dp[i] = dp[best1] + 1;
                    parent[i]=best1;
                }
                if(best0 == -1 || dp[i]>dp[best0]){
                    best0 = i;
                }
            }else{
                if(best0 != -1){
                    dp[i] = dp[best0] + 1;
                    parent[i] = best0;
                }
                if(best1 == -1 || dp[i]>dp[best1]){
                    best1 = i;
                }
            }
        }

        int idx = max_element(dp.begin(), dp.end()) - dp.begin();

        // reconstruct subsequence
        vector<string> subseq;
        while (idx != -1) {
            subseq.push_back(words[idx]);
            idx = parent[idx];
        }
        reverse(subseq.begin(), subseq.end());
        return subseq;
    }
};