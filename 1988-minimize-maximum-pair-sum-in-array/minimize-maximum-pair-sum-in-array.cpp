class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        vector<int>maxi;
        while(i<j){
             maxi.push_back(nums[i]+nums[j]);
             i++;
             j--;
        }
        int max_no= maxi[0];
        for(int i=1;i<maxi.size();i++){
            if(maxi[i]>max_no) max_no = maxi[i];
        }
        return max_no;
    }
};