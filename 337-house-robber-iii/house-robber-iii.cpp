/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int f(TreeNode* root,bool parent,unordered_map<TreeNode*,vector<int>>& dp){
        if(root == NULL)return 0;
        int op1 =0;
        if(dp.find(root) == dp.end()) dp[root] = vector<int>(2,-1);
        if(dp[root][parent] != -1)return dp[root][parent];
        if(parent == false){
             op1 = root->val + f(root->left,true,dp)+f(root->right,true,dp);
        }
        
            int op2 = f(root->left,false,dp) + f(root->right,false,dp); 
        return dp[root][parent] = max(op1,op2);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,vector<int>>dp;
        return f(root,false,dp);
    }
};