class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        //max heap
        priority_queue<int>pq;
        int sum = 0;
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
            sum += piles[i];
        }
        for(int i=1;i<=k;i++){
            int max_el = pq.top();
            pq.pop();
            int remove = max_el/2;
            sum -= remove;
            pq.push(max_el - remove);
        }
       return sum;
    }
};