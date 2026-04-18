class Solution {
public:
    int mirrorDistance(int n) {
       string s = to_string(n);
        string t = "";
        for(int i=s.length()-1;i>=0;i--){
            t += s[i];
        }
        int x = stoi(t);
        return abs(n-x);
    }
};