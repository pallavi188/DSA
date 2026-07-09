class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int pointUnique = 0;
        int iterator = pointUnique + 1;
        while(iterator < n){
            if(nums[pointUnique]==nums[iterator]){
                iterator++;
            }else{
                nums[pointUnique + 1] = nums[iterator];
                    pointUnique++;
                    iterator++;
                
            }
        }
        return pointUnique + 1;
    }
};