class Solution {
public:
    bool checkString(string s) {
        int cntA = 0,cntB = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a')cntA++;
            else
            cntB++;
        }
        if(cntA==0)return true;
        else{
            for(int j=0;j<cntA;j++){
                if(s[j]!='a')return false;
            }
        }
        return true;
    }
};