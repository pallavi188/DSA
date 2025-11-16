class Solution {
public:
const int M = 1e9+7;
    int numSub(string s) {
      int result =0;
      int cnt = 0;
      for(char ch:s){
        if(ch == '1'){
            cnt++;
            result = (result+cnt)%M;
        }else{
            cnt =0;
        }
      }
      return result;
    }
};