class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = -1e9;
        int l = 0;
        int r = n-1;
        while(l<r){
            maxWater = max(maxWater , (r-l)* min(height[l],height[r]));
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxWater;
    }
};