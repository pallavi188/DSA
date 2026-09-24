class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefixZero(n+1,0);
        for(int i=0;i<n;i++){
            if(nums[i] == 0)
              prefixZero[i+1] = prefixZero[i] + 1;
            else 
              prefixZero[i+1] = prefixZero[i];  
        }
        int maxLen = 0;
        //try every index as a starting point
        for(int st=0;st<n;st++){
            int l = st,h = n-1;
            int farthest = st - 1;
            //binary search to find the farthest zero
            while(l <= h){
                int mid = l + (h-l)/2;
                int zeroCnt = prefixZero[mid+1] - prefixZero[st];
                
                if(zeroCnt <= k){
                    farthest = mid;
                    l = mid+1;
                }
                else{
                    h = mid-1;
                }
            }
            if(farthest >= st){
                maxLen = max(maxLen,farthest-st+1);
            }
        }
        return maxLen;
    }
};