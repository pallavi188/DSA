class Solution {
public:
    int countSegments(string s) {
        if(s=="")return 0;
        istringstream iss(s);
        string str{};
        vector<string>v{};
        while(iss>>str) v.push_back(str);
        return v.size();
    }
};