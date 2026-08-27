class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>LIS(n,1);
        vector<int>LDS(n,1);
        //lis calculation
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    LIS[i] = max(LIS[i],LIS[j]+1);
                }
            }
        }
        //LDS calculation
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i] > nums[j]){
                    LDS[i] = max(LDS[i],LDS[j]+1);
                }
            }
        }
        int minRemoval = 1e9;
        for(int i=0;i<n;i++){//treate each elements as peak element
            if(LIS[i] > 1 && LDS[i]>1){
                minRemoval = min(minRemoval,n - LIS[i]-LDS[i]+1);
            }
        }
        return minRemoval;
    }
};