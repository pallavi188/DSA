class Solution {
public:
    bool isCapital(char ch){
        return (ch >= 'A' && ch <='Z');
    }
    bool detectCapitalUse(string word) {
        int n = word.length();
        int capCnt = 0;
        for(char c : word){
            if(isCapital(c)){
                capCnt++;
            }
        }
        if(capCnt == 0 || capCnt == n || (capCnt == 1 && isCapital(word[0])))
        return true;
        return false;
    }
};