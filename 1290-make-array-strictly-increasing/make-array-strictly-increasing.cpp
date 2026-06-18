class Solution {
public:
    map<pair<int,int>,int>mp;
    int f(int idx,int prev,vector<int>& arr1, vector<int>& arr2){
        int n = arr1.size();
        if(idx >= n) return 0;
        int op1 = 1e9+1;
        int op2 = 1e9+1;
        if(mp.find({idx,prev}) != mp.end()) return mp[{idx,prev}];
        if(arr1[idx] > prev){
           //skip 
          op1 = f(idx+1,arr1[idx],arr1,arr2);
        }
        auto it = upper_bound(begin(arr2),end(arr2),prev);
        if(it != arr2.end()){
            int j = it - begin(arr2);
           
            op2 = 1 + f(idx+1,arr2[j],arr1,arr2);
        }
        return mp[{idx,prev}] = min(op1,op2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        mp.clear();
        sort(arr2.begin(),arr2.end());
        int res = f(0,-1e9,arr1,arr2);
        if(res == 1e9+1) return -1;
        else
        return res;
    }
};