class Solution {
public:
    int product(int n){
        int prod = 1;
        while(n>0){
            int dig = n%10;
            prod *= dig;
            n = n/10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int p = product(n);
        int ans = 0;
        if(p%t == 0)return n;
        else{
            for(int i=1;i<=9;i++){
                int num = n+i;
                if(product(num)%t == 0){
                    ans = num;
                    break;
                }
            }
        }
        return ans;
    }
};