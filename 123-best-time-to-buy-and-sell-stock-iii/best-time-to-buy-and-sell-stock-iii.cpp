class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>ahead(5,0),cur(5,0);
        for(int idx=n-1;idx>=0;idx--){
            for(int trans =3;trans>=0;trans--){
                if(trans%2==0)
                cur[trans] = max(-prices[idx]+ ahead[trans+1],ahead[trans]);
                else
                cur[trans] = max(prices[idx] + ahead[trans+1],ahead[trans]);
            }
            ahead = cur;
        }
        return ahead[0];
    }
};