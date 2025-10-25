class Solution {
public:
    int totalMoney(int n) {
        int monday = 1;
        int totalmoney = 0;
        while(n>0){
            for(int day=0;day<7 && n>0;day++){
                totalmoney += monday + day;
                n--;
            }
            monday++;
        }
        return totalmoney;
    }
};