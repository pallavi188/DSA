class Solution {
public:
    void solve(int idx,string digits,string temp,unordered_map<char,string>&mp,vector<string>&result){
        if(idx >= digits.length()){
            result.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            solve(idx+1,digits,temp,mp,result);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        vector<string>result;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp = "";
        solve(0,digits,temp,mp,result);
        return result;
    }
};