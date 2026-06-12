class Solution {
public:
   
    int maxProfit(vector<int>& prices, int fee) {
        int n =prices.size();
        vector<int>ahead(2,0);
        vector<int>cur(2,0);
        ahead[0] =ahead[1] =0;
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                if(buy)
                cur[buy]= max(-prices[idx]+ahead[0],ahead[1]);
                else
                cur[buy]= max(prices[idx]-fee + ahead[1],ahead[0]);
            }
            ahead = cur;
        }
        return ahead[1];
    }
};