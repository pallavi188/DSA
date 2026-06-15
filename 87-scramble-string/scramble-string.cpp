class Solution {
public:
    unordered_map<string,bool>mp;

    bool f(string s1,string s2){
        if(s1.length() != s2.length()) return false;
        if(s1 == s2) return true;
        string key = s1+""+s2;
        if(mp.find(key) != mp.end()) return mp[key];
        int n = s1.length();
        for(int i=1;i<n;i++){
            //not swap
            if(f(s1.substr(0,i),s2.substr(0,i)) && f(s1.substr(i,n-i),s2.substr(i,n-i)))
            return mp[key]= true;
            // swap
            if(f(s1.substr(i,n-i),s2.substr(0,n-i)) && f(s1.substr(0,i),s2.substr(n-i,i)))
            return mp[key]= true;
        }
        return mp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        mp.clear();
        return f(s1,s2);
    }
};