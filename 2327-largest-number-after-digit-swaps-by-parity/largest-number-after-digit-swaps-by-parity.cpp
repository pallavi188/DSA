class Solution {
public:
    int largestInteger(int num) {
        vector<int>nums,ev,od;
        while(num>0){
            int dig = num%10;
            nums.push_back(dig);
            num = num/10 ;
        }
        
        reverse(nums.begin(),nums.end());

        int n = nums.size();
       for(int i=0;i<n;i++){
              if(nums[i]%2 == 0){
                ev.push_back(nums[i]);
              }else{
                od.push_back(nums[i]);
              }
       }
       sort(ev.begin(),ev.end(),greater<>());
       sort(od.begin(),od.end(),greater<>());

        int ei = 0, oi = 0;
        int result = 0;
        
       
        for (int d : nums) {
            result *= 10;
            if (d % 2 == 0) {
                result += ev[ei++];
            } else {
                result += od[oi++];
            }
        }
        return result;
    }
};