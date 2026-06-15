class Solution {
public:
    
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        sort(sat.begin(),sat.end());
        vector<int>ahead(n+2,0),cur(n+2,0);
        for(int idx=n-1;idx>=0;idx--){
            for(int time=1;time<=n;time++){
                int take = time*sat[idx] + ahead[time+1];
                int not_take = ahead[time];
                cur[time] = max(take,not_take);
            }
            ahead = cur;
        }
        return ahead[1];
    }
};