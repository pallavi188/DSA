class Solution {
public:
    bool isGood(vector<int>& nums) {
        int m = nums.size();
        sort(nums.begin(),nums.end());
        
        int n =nums[m-1];
        if(m!=n+1) return false;
        if(nums[nums.size()-2] != nums[nums.size()-1]) return false;
        for(int i=0;i<n-1;i++){
            if(nums[i] != i+1) return false;
        }
        return true;
    }
};