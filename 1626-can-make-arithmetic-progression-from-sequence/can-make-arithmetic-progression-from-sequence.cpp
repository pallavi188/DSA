class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        bool ans = true;
        sort(arr.begin(),arr.end());
          int diff = arr[1]-arr[0];
        for(int i=2;i<n;i++){
           if(diff!=arr[i]-arr[i-1])
            ans=false;
        }
        return ans;
    }
};