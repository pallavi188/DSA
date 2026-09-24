class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        if(k < 0 || k>n)return -1;
        if(k == 0)return 0;
        if(k == n)return accumulate(card.begin(),card.end(),0);
        int currScore = 0;
        for(int i=0;i<k;i++){
            currScore += card[i];
        }  
        int maxScore = currScore;
        int rightIdx = n-1;
        for(int i=k-1;i>=0;i--){
            currScore -= card[i];
            currScore += card[rightIdx];rightIdx--;
            maxScore = max(maxScore , currScore);
        }
        return maxScore;
    }

};