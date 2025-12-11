class Solution {
public:
    int minOperations(vector<int>& nums) {
        int no =0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                  no +=  nums[i-1]-nums[i] + 1;
                   nums[i] += (nums[i-1]-nums[i]+1);
            }else if(nums[i]==nums[i-1]) {
                
                no += 1;
                nums[i] += 1;
            }

        }
        return no;
    }
};