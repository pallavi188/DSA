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
    int height(TreeNode* root){
        if(root==NULL) return 0;
      int left_height = 1+height(root->left);
        int right_height = 1+height(root->right);
        return max(left_height,right_height);
    }
    int maxDepth(TreeNode* root) {
        return height(root);
    }
};