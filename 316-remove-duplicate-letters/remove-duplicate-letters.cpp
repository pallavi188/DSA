class Solution {
public:
    string removeDuplicateLetters(string s) {
         int n = s.length();
         vector<int>lastIndex(26);
         vector<bool>takenChar(26,false);
         string result = "";
         for(int i=0;i<n;i++){
            char ch = s[i];
            lastIndex[ch-'a'] = i;
         }
         for(int i=0;i<n;i++){
            char ch = s[i];
            int idx = ch-'a';

            if(takenChar[idx] == true)continue;
            while(result.length() > 0 && result.back() > ch && lastIndex[result.back()-'a'] > i){
                takenChar[result.back()-'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            takenChar[idx] = true;
         }
         return result;
    }
};