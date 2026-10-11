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
    //inorder traversal of the given bst
    void inorder(TreeNode* root,vector<int>&order){
        if(!root)return;
        inorder(root->left,order);
        order.push_back(root->val);
        inorder(root->right,order);
    }
    //again inorder traversal to replace incorrect node value with correct one
    void replaceVal(TreeNode*root,vector<int>&order,int &idx){
        if(!root)return;
        replaceVal(root->left,order,idx);
        root->val = order[idx++];
        replaceVal(root->right,order,idx);
    }
    void recoverTree(TreeNode* root) {
        vector<int>order;
        inorder(root,order);
        sort(order.begin(),order.end());
        int idx = 0;
        replaceVal(root,order,idx);
        
    }
};