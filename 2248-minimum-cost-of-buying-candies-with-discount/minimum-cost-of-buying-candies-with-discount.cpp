class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<>());
        int n=cost.size();
        int mincost =0;
        for(int i=0;i<n;i++){
            mincost += cost[i];
            if( (i+1)%3 == 0) mincost -= cost[i];
        }
        return mincost;
    }
};