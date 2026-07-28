class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        string s1 = "";
        string mid = "";
        for(auto &it : mp){
            if(it.second % 2 != 0) {
              mid += it.first;
              it.second--;
            }
            int n = it.second/2;
           //first half
            while(n--){
                s1 += it.first;
            }
        }
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        string str = s1 + mid + s2;
        return str;
    }
};