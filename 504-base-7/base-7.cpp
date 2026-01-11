class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)return "0";
        bool neg = false;
        if(num<0){
            neg = true;
            num = -num;
        }
        string res = "";
        while(num>0){
            int rem = num%7;
            res = char(rem +'0') + res;
            num = num/7;
        }
       if(neg) res = "-"+res;
       return res;
    }
};