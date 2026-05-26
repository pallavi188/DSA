class Solution {
public:
    int numberOfSpecialChars(string word) {
      unordered_set<char>st(word.begin(),word.end());
      int cnt =0;
      for(char ch : st){
        if(isupper(ch) && st.count(tolower(ch))){
           cnt++;
        }
      }
      return cnt;
    }
};