class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0,zeroCnt = 0,maxLen=0;
        for(int j=0;j<n;j++){
            if(nums[j] == 0)zeroCnt++;
            while(zeroCnt>k){
                if(nums[l]==0){
                    zeroCnt--;
                }
                l++;
            }
            maxLen = max(maxLen,j-l+1);
        }
        return maxLen;
    }
};