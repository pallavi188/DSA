class Solution {
public:
    int mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mini = 0;
        int maxi = n-1;
        int result = 0;
        vector<int>power(n);
            power[0] = 1;
            for(int i=1;i<n;i++){
                power[i] = (2*power[i-1])%mod;
            }
        while(mini <= maxi){
            if(nums[mini] + nums[maxi] <= target){
                result =(int)(result + power[maxi-mini])%mod;
                mini++;
            }else{
                maxi--;
            }
        }
        return result;
    }
};