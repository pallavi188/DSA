class Solution {
public:
    int mod = 1e9+7;
    vector<int>findNSE(vector<int>&arr){
        int n = arr.size();
        vector<int>NSE(n);
        stack<int>st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i])st.pop();
            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return NSE;
    }
    vector<int>findPSEE(vector<int>&arr){
        int n = arr.size();
        vector<int>PSEE(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            PSEE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return PSEE;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>nse = findNSE(arr);
        vector<int>pse = findPSEE(arr);
        int total = 0;
        for(int i=0;i<n;i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (right*left * 1LL* arr[i]) % mod)%mod;
        }
        return total;
    }
};