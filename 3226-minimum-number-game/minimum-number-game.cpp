class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans(n),A,B;
        for(int i=0;i<n;i++){
            if(i%2==0){
                A.push_back(nums[i]);
            }else {
                B.push_back(nums[i]);
            }
        }
        int j =0,k=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
               ans[i]=B[j];
                j++;
            }else{
            ans[i]=A[k];
                k++;
            }
        }
        return ans;
    }
};