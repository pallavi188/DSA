class Solution {
public:
    int splitNum(int num) {
        vector<int>nums;
        while(num>0){
            int dig = num%10;
            nums.push_back(dig);
            num = num/10;
        }
        sort(nums.begin(),nums.end());
        long long num1=0,num2=0;

        for(int i=0;i<nums.size();i++){
          if(i%2 == 0){
            num1 = num1*10 + nums[i];
          }  else{
            num2 = num2*10 + nums[i];
          }
        }
        return num1+num2;
    }
};