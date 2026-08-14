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
    int height(TreeNode* root,int &maxDia){
        if(!root) return 0;
        int leftHeight = height(root->left,maxDia);
        int rightHeight = height(root->right,maxDia);
        maxDia = max(maxDia,leftHeight+rightHeight);
        return 1 + max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       int maxDia = 0;
       height(root,maxDia);
       return maxDia;
    }
};