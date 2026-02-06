class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
        int n= nums.size();
        int res = n-1;
        for(int i=0;i<n;++i){
            int left = i,right=n-1,valid =i;
            while(left <= right){
                int mid = (left+right)/2 ;
                if((long long)nums[mid] <= (long long)nums[i] * k){
                    valid = mid;
                    left = mid+1;
                }else{
                    right = mid -1;
                }
            }
            res = min(res,i+(n-1-valid));
        }
        return res;
    }
};