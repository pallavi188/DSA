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
    void postOrder(TreeNode* root,vector<int>&order){
        if(root == NULL)return;
        postOrder(root->left,order);
        postOrder(root->right,order);
        order.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>order;
        postOrder(root,order);
        return order;
    }
};