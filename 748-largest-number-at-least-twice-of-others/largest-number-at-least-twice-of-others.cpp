class Solution {
public:
    int dominantIndex(vector<int>& nums) {
       int largest = INT_MIN,secondlarge = INT_MIN;
       int index = -1;
       if(nums.size()==1) return 0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]>largest){
            secondlarge = largest;
            largest = nums[i];
            index = i;
        }else if(nums[i]>secondlarge){
            secondlarge = nums[i];
        }
       }
       if(largest >= 2*secondlarge){
           return index;
       }
       return -1;
    }
};