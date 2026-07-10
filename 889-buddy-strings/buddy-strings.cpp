class Solution {
public:
    bool checkFreq(string s){
        unordered_map<char,int>mpp;
        for(char &ch : s){
            mpp[ch]++;
        }
        for(auto &it : mpp){
            if(it.second >= 2){
                return true;
              
            }
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(n != m)return false;
        if(s == goal){
            return checkFreq(s);
        }
        vector<int>index;
        for(int i=0;i<n;i++){
            if(s[i] != goal[i]){
                index.push_back(i);
            }
        }
        if(index.size() != 2) return false;
        else{
            char ch1 = s[index[0]];
            char ch2 = s[index[1]];
            s[index[0]] = ch2;
            s[index[1]] = ch1;
            if(s != goal)return false;
        }
        return true;
    }
};