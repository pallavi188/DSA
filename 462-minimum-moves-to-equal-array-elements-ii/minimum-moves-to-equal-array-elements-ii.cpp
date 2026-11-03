class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mid_el = nums[n/2];
        int minMove = 0;
        for(int i=0;i<n;i++){
            minMove += abs(mid_el - nums[i]);
        }
        return minMove;
    }
};