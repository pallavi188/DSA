class Solution {
public:
    string frequencySort(string s) {
          int n = s.length();
          string str = "";
          unordered_map<char,int>mp;
          for(int i=0;i<n;i++){
            mp[s[i]]++;
          }   
          vector<pair<char,int>>v(mp.begin(),mp.end());
          sort(v.begin(),v.end(),[](auto &a,auto &b){
              if(a.second != b.second) return a.second > b.second;
              return a.first < b.first;
          });
          for(auto it : v){
            for(int i=0;i<it.second;i++)
            str += it.first;
          }
          return str;
    }
};