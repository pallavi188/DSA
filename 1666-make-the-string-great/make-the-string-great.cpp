class Solution {
public:
    string makeGood(string s) {
        string goodStr = "";
        for(char &ch : s){
            if(!goodStr.empty() && (goodStr.back() + 32 == ch ||
                goodStr.back()-32 == ch)){
                goodStr.pop_back();
            }else{
                goodStr.push_back(ch);
            }
        }
        return goodStr;
    }
};