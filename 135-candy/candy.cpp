class Solution {
public:
    int candy(vector<int>& rate) {
        int n = rate.size();
        vector<int>left(n),right(n);
        left[0] = 1;
        right[n-1] = 1;
        //considering left array only
        for(int i=1;i<n;i++){
          if(rate[i] > rate[i-1]) left[i] = left[i-1]+1;
          else
          left[i] = 1;
        }
        for(int j=n-2;j>=0;j--){
            if(rate[j] > rate[j+1]) right[j] = right[j+1]+1;
            else
               right[j] = 1;
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += max(left[i],right[i]);
        }
        return sum;
    }
};