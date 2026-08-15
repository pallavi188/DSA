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
    TreeNode* helper(vector<int>&inorder,int inSt,int inEnd,vector<int>&postorder,int pSt,int pEnd,unordered_map<int,int>&mp){
        if(inSt > inEnd || pSt>pEnd)return NULL;
        TreeNode* root = new TreeNode(postorder[pEnd]);
        int inRoot = mp[root->val];
        int isLeft = inRoot - inSt;

        root->left = helper(inorder,inSt,inRoot-1,postorder,pSt,pSt+isLeft -1,mp);
        root->right = helper(inorder,inRoot+1,inEnd,postorder,pSt+isLeft,pEnd-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
};