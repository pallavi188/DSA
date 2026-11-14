class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        //brute force generate all subarray of size in between l and r and find there sum and return the minimum one
        //optimal fixed length sliding window
        int n = nums.size();
        int best = INT_MAX;
        for(int len = l;len <= r;len++){
            int sum = 0;
            for(int i=0;i<n;i++){
                sum += nums[i];
                if(i >= len)sum -= nums[i-len];
                if(i >= len-1 && sum > 0 && sum < best)best = sum;
            }
        }
        return best == INT_MAX ? -1 : best;
    }
};