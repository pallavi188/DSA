class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>position;
        vector<int>ans;
        for(int i=0;i<s.length();i++){
            if(s[i]==c)
            position.push_back(i);
        }
        for(int i=0;i<s.length();i++){
            int shortest_dis = INT_MAX;
            for(int j=0;j<position.size();j++){
                shortest_dis = min(shortest_dis,abs(i-position[j]));

            }
            ans.push_back(shortest_dis);
        }
        return ans;
    }
};