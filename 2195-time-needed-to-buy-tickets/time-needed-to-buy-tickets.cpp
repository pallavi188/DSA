class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        int i=0,time=0;
        int reqP = tickets[k];
        while(i < tickets.size()){
            q.push({i,tickets[i]});
            i++;
        }
        while(reqP != 0){
            int tic = q.front().second;
            int idx = q.front().first;
            if(idx == k) reqP--;
            time++;
            q.pop();
            if((tic-1) != 0){
                q.push({idx,tic-1});
            }
        }
        return time;
    }
};