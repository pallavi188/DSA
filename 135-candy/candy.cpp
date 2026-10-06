class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        int sum = 1 , i = 1;
        while(i < n){
            if(rating[i] == rating[i-1]){
                sum += 1;
                i++;
                continue;
            }
            //increasing slope
            int peak = 1;
            while(i<n && rating[i]>rating[i-1]){
                peak += 1;
                sum += peak;
                i++;
            }
            int down = 1;
            //decreasing slope
            while(i<n && rating[i]<rating[i-1]){
                sum += down;
                i++;
                down++;
            }
            if(down > peak) sum += (down - peak);
        }
        return sum;
    }
};