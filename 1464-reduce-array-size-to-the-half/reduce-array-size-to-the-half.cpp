class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>freq;
        int n = arr.size();
        int m = n/2;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        vector<int>counts;
        for(auto &p : freq){
            counts.push_back(p.second);
        }
        sort(counts.begin(),counts.end(),greater<>());
        int removed = 0;
        int ans =0;
        for(int count : counts){
            removed += count;
            ans++;
            if(removed >= m) break;
        }
        return ans;
    }
};