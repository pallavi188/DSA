class Solution {
public:
    string frequencySort(string s) {
        struct comp{
            bool operator()(pair<char,int>&p1,pair<char,int>&p2){
                return p1.second < p2.second;
            }
        };
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq;
        unordered_map<char,int>mp;
        for(char &ch : s){
            mp[ch]++;
        }
        for(auto &it : mp){
            pq.push({it.first,it.second});
        }
        string result = "";
        while(!pq.empty()){
            pair<char,int>temp = pq.top();
            pq.pop();
            result += string(temp.second,temp.first);
        }
        return result;
    }
};