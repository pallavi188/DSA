class Solution {
public:

    vector<int> parent, sz;
    
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if(sz[a] < sz[b]) swap(a,b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    int minOperations(vector<int>& nums) {
     
           int n = nums.size();
        parent.resize(n);
        sz.assign(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;

        unordered_map<int, vector<int>> positions;
        int mx = 0;
        for(int i = 0; i < n; i++){
            positions[nums[i]].push_back(i);
            mx = max(mx, nums[i]);
        }

        vector<bool> active(n, false);
        int ans = 0;

        for(int v = mx; v >= 1; v--){
            if(!positions.count(v)) continue;

            for(int i : positions[v]) {
                active[i] = true;
                if(i > 0 && active[i-1]) unite(i, i-1);
                if(i+1 < n && active[i+1]) unite(i, i+1);
            }

            unordered_set<int> roots;
            for(int i : positions[v]) {
                roots.insert(find(i));
            }

            ans += roots.size();
        }

        return ans;

    }
};