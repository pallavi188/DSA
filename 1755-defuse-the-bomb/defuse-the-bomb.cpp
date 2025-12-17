class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans(n);
        if(k>0){
           for(int i=0;i<n;i++){
            int sum =0;
            for(int j = 1;j<=k;j++){
                sum += code[(i+j)%n];
            }
           ans[i]=sum;
           }
        }
        else if(k<0){
            for(int i=0;i<n;i++){
                int sum1=0;
                for(int j=1;j<=abs(k);j++){
                    sum1 += code[(i-j+n)%n];
                }
                ans[i]=sum1;
            }
        }else{
            for(int i=0;i<n;i++){
                ans[i]=0;
            }
        }
        
        return ans;
    }
};