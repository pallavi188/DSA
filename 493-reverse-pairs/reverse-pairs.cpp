class Solution {
public:
    int merge(vector<int>&nums,int st,int mid,int end){
        vector<int>temp;
        int i = st,j = mid+1;
        int revCnt =0;
        //count rev pairs
        for(int i=st;i<=mid;i++){
            while(j <= end && nums[i] > 2LL*nums[j]){
                j++;
            }
            revCnt += (j - (mid+1));
        }
        i =st;
        j = mid+1;
        while(i<=mid && j <= end){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= end){
            temp.push_back(nums[j]);
            j++;
        }
        for(int idx=0;idx<temp.size();idx++){
            nums[idx+st] = temp[idx];
        }
        return revCnt;
    }
    int mergeSort(vector<int>&nums,int st,int end){
        int cnt =0;
        if(st < end){
            int mid = st + (end-st)/2;
            int leftCnt = mergeSort(nums,st,mid);
            int rightCnt = mergeSort(nums,mid+1,end);
            int revCnt = merge(nums,st,mid,end);
            cnt = leftCnt + rightCnt+revCnt;
        }
           return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);
    }
};