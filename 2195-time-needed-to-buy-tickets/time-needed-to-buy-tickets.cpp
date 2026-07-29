class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        for(int i=0;i<tickets.size();i++){
            q.push({tickets[i],i});
        }
        int time = 0;
        while(true){
            int val = q.front().first;
            int idx = q.front().second;
            q.pop();
            if(val-1 == 0 && idx == k)return time+1;
            if(val-1 > 0)
            q.push({val-1,idx});
            time++;
        }

    }
};