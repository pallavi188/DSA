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
    void inorder(TreeNode*root,int k,int &cntSmallest,int &kthSmallest){
        if(!root || cntSmallest>=k)return;
        //left
        inorder(root->left,k,cntSmallest,kthSmallest);
        //root == check if it is the kth smallest element
        cntSmallest++;
        if(cntSmallest == k){
            kthSmallest = root->val;
            return;
        }
        //right
        inorder(root->right,k,cntSmallest,kthSmallest);
    }
    int kthSmallest(TreeNode* root, int k) {
       int cntSmallest = 0,kthSmallest = -1;
       inorder(root,k,cntSmallest,kthSmallest);
       return kthSmallest;
    }
};