class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int temp = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1)
            temp = temp+nums[i];
            else break;
        }
        sort(nums.begin(),nums.end());
        int i= 0;
        while(binary_search(nums.begin(),nums.end(),temp)){
            temp++;
        }
        return temp;
    }
};