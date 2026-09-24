class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        if(k < 0 || k>n)return -1;
        if(k == 0)return 0;
        if(k == n)return accumulate(card.begin(),card.end(),0);
        int maxScore = -1e9;
        vector<int>leftSum(k+1,0),rightSum(k+1,0);
        //precomputing sum from left and right cards
        for(int i=1;i<=k;i++){
            leftSum[i] = leftSum[i-1] + card[i-1];
            rightSum[i] = rightSum[i-1] + card[n-i];
        }
        //combine each valid left count and right count
        for(int l=0;l<=k;l++){
            int r = k-l;
            int currScore = leftSum[l] + rightSum[r];
            maxScore = max(maxScore,currScore);
        }
        return maxScore;
    }
};