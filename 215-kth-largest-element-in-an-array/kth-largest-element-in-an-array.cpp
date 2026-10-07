class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        int p = n-k;
        while(p>=0){
            if(p != 0){
                pq.pop();
                p--;
            }else{
                return pq.top();
            }
        }
        return 0;
    }
};