class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
         int n = nums.size();
        vector<int>leftSum(n),rightSum(n),answer(n);
       
        int totalSum =0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }
        for(int i=1;i<n;i++){
            leftSum[0] = 0;
            rightSum[0]=totalSum - nums[0];
            leftSum[i] = nums[i-1]+leftSum[i-1];
            rightSum[i] = rightSum[i-1] - nums[i];
        }
        for(int i=0;i<n;i++){
            answer[i] = abs(leftSum[i]-rightSum[i]);
        }
        return answer;
    }
};