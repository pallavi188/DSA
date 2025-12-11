class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum =0,rsum =0,maxsum =0;
      int rightIdx = cardPoints.size()-1;
        for(int i=0;i<k;i++){
            lsum += cardPoints[i];
            maxsum = lsum;
        }
        for(int j = k-1;j>=0;j--){
            lsum -=cardPoints[j];
            rsum += cardPoints[rightIdx];
            rightIdx--;
            maxsum = max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};