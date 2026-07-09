class Solution {
public:
    int mod = 1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        //map will store the  index at which the number last appears
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]] = i;
        }
        int i=0,j=0;
        j = max(j,mpp[nums[0]]);
        int result = 1;
        while(i<n){
            if(i>j){
                result = (result*2)%mod;
            }
            j = max(j,mpp[nums[i]]);
            i++;
        }
        return result;
    }
};