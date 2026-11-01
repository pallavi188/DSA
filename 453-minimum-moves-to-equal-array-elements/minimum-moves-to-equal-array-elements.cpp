class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minEl = nums[0];
        int reqMoves = 0;
        for(int i=1;i<nums.size();i++){
            minEl = min(minEl,nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            reqMoves += abs(minEl - nums[i]);
        }
        return reqMoves;
    }
};