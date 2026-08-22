class Solution {
public:
    int digit(int n){
        int sum =0,prod = 1;
          
        while(n>0){
        int dig = n%10;
        sum += dig;
        prod *= dig;
        n = n/10;
        }
       return (sum + prod);
    }
    bool checkDivisibility(int n) {
        int num = digit(n);
        if(n % num == 0)return true;
        else
        return false;
    }
};