class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int ev =0,od=0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2 == 0)ev++;
            else
                od++;
        }
        if((ev !=0 && od !=0)||ev == n || od==n)return true;
        return false;
    }
};