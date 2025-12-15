class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int ans= 0;
        if(prices[0]+prices[1]<=money){
            ans = money-(prices[0]+prices[1]);
        }else{
            ans =money;
        }
        return ans;
    }
};