class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        
        for(int l=0;l<nums.size();l++){
            for(int r=0;r<nums.size();r++){
                if(abs(l-r)>=indexDifference && abs(nums[l]-nums[r])>=valueDifference){
                   return {l,r};
                }
            }
        }
       return {-1,-1};
    }
};