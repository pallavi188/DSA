class Solution {
public:
    string removeKdigits(string num, int k) {
         stack<char>st;
         int remaining = k;
         for(int i=0;i<num.size();i++){
            while(remaining>0 && !st.empty() && st.top()>num[i]){
                st.pop();
                remaining--;
            }
            st.push(num[i]);
         }
         while(remaining > 0 && !st.empty()){
            st.pop();
            remaining--;
         }
         string result;
         while(!st.empty()){
            result.push_back(st.top());
            st.pop();
         }
         reverse(result.begin(),result.end());
         //remove the starting zeroes
         int start =0;
         while(start < result.size() && result[start] == '0')start++;

         if(start == result.size())return "0";
         return result.substr(start);
    }
};