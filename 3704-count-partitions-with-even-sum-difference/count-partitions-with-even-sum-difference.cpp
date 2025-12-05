class Solution {
public:
    int countPartitions(vector<int>& nums) {
       
        int left_sum = 0, right_sum = 0,count =0;
        int total =0;
        for(int x:nums) total += x;
        for(int i =0;i<nums.size()-1;i++){
            left_sum += nums[i];
            right_sum = total-left_sum;
            if(abs(left_sum - right_sum )%2 == 0) 
            count++;
        }
        return count;
    }
};