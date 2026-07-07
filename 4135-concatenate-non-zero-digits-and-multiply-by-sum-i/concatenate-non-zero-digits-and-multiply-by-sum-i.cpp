class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int>A;
        while(n>0){
            int dig = n%10;
        A.push_back(dig);
        n = n/10;
        }
        reverse(A.begin(),A.end());
        int N=A.size();
        int sum =0;
        for(int x:A){
            sum += x;
        }
        long long num=0;
        long long base =1;
        for(int j=N-1;j>=0;j--){
            if(A[j]!=0){
                num +=A[j]*base;
                base *= 10;
            }
        }
       return num*sum;
    }
    
};