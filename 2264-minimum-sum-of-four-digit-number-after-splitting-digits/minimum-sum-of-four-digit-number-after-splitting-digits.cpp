class Solution {
public:
    int minimumSum(int num) {
        vector<int>A;
        int num1,num2;
        while(num>0){
             int dig = num%10;
             A.push_back(dig);
             num = num/10;
        }
        sort(A.begin(),A.end());
        num1 = 10*A[0]+A[2];
        num2 = 10*A[1]+A[3];
        return num1+num2;
    }
};