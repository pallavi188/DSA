class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>num;
        for(int i=1;i<=9;++i){
            int nums = i;
            for(int j=i+1;j<=9;++j){
                nums = nums*10 + j;
                if(nums >= low && nums <= high){
                    num.push_back(nums);
                }
            }
        }
        sort(num.begin(),num.end());
        return num;
    }
};