class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>evn,od,result;
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0){
                evn.push_back(nums[i]);
            }else{
                od.push_back(nums[i]);
            }
        }
        sort(evn.begin(),evn.end());
        sort(od.begin(),od.end(),greater<>());
        int e=0,o=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                result.push_back(evn[e++]);
            }else{
                result.push_back(od[o++]);
            }
        }
        return result;
    }
};