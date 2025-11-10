class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int>mp;
        for(char c: s){
            mp[c]++;
        }
        vector<int> freq;
        for(auto &p : mp) freq.push_back(p.second);
        
        sort(freq.begin(), freq.end()); // ascending
        
        int distinct = freq.size();
        if(distinct <= k) return 0; // already OK
        
        int removeTypes = distinct - k;
        int deletions = 0;

        for(int i = 0; i < removeTypes; i++){
            deletions += freq[i];
        }

        return deletions;
    }
};