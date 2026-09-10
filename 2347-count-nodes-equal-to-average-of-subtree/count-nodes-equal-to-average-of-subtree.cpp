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
    int findSum(TreeNode* root,int &cntNode){
        if(root == NULL)return 0;
        cntNode++;
        int lSum = findSum(root->left,cntNode);
        int rSum = findSum(root->right,cntNode);
        return lSum + rSum + root->val;
    }
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL)return 0;
        int res =0;
        int cntNode =0;
        int sum = findSum(root,cntNode);
        if(root->val == sum/cntNode)res++;
        res += averageOfSubtree(root->left);
        res += averageOfSubtree(root->right);
        return res;
    }
};