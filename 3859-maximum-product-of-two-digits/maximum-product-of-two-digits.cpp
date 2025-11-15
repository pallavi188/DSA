class Solution {
public:
    int maxProduct(int n) {
        vector<int>num;
        while(n>0){
            num.push_back(n%10);
            n = n/10;
        }
        sort(num.begin(),num.end(),greater<>());
        int pro = num[0]*num[1];
        return pro;
    }
};