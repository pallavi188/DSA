class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            if(stone1 != stone2){
                int wt = stone1-stone2;
                pq.push(wt);
            }
        }
        if(pq.size() == 0)return 0;
        else 
        return pq.top();
    }
};