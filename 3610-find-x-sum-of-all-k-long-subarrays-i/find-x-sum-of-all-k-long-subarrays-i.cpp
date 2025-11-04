class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        

   
        int n = nums.size();
        vector<int> ans(n - k + 1);
        
        unordered_map<int,int> freq; 
        // multiset sorted by:
        // frequency descending, value descending
        auto cmp = [&](const pair<int,int> &a, const pair<int,int> &b){
            if(a.first != b.first) return a.first > b.first;
            return a.second > b.second;
        };
        multiset<pair<int,int>, decltype(cmp)> ms(cmp); 
        
        auto add = [&](int val){
            int old = freq[val];
            if(old > 0){
                ms.erase(ms.find({old, val}));
            }
            freq[val]++;
            ms.insert({freq[val], val});
        };
        
        auto remove = [&](int val){
            int old = freq[val];
            ms.erase(ms.find({old, val}));
            freq[val]--;
            if(freq[val] > 0) ms.insert({freq[val], val});
        };
        
        // initialize first window
        for(int i = 0; i < k; i++){
            add(nums[i]);
        }
        
        auto calc = [&](){
            long long sum = 0;
            int cnt = 0;
            for(auto &p : ms){
                if(cnt == x) break;
                sum += 1LL * p.first * p.second;
                cnt++;
            }
            return sum;
        };
        
        ans[0] = calc();
        
        // slide window
        for(int i = 1; i <= n - k; i++){
            remove(nums[i - 1]);
            add(nums[i + k - 1]);
            ans[i] = calc();
        }
        
        return ans;
    }
};
