/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxPath(TreeNode* root,int &maxVal){
        if(!root) return 0;
        int leftSum = max(0,maxPath(root->left,maxVal));
        int rightSum = max(0,maxPath(root->right,maxVal));
        maxVal = max(maxVal,leftSum + rightSum + root->val);
        return root->val + max(leftSum , rightSum);
    }
    int maxPathSum(TreeNode* root) {
       int maxVal = -1e9;
       maxPath(root,maxVal);
       return maxVal;
    }
};