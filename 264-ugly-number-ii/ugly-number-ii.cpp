class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>arr(n+1);
        int i2,i3,i5;
        i2 = i3 = i5 =1;
        arr[1] = 1;
        for(int i=2;i<=n;i++){
          int i2un = arr[i2]*2;
          int i3un = arr[i3]*3;
          int i5un = arr[i5]*5;
          int minUglyNo = min({i2un,i3un,i5un});
          arr[i] = minUglyNo;
          if(minUglyNo == i2un)i2++;
          if(minUglyNo == i3un) i3++;
          if(minUglyNo == i5un) i5++;
        }
        return arr[n];
    }
};