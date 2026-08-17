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
    void inorder(TreeNode* root,vector<TreeNode*>&order){
        if(!root)return;
        inorder(root->left,order);
        order.push_back(root);
        inorder(root->right,order);
    }
    void recoverTree(TreeNode* root) {
         vector<TreeNode*>order;
         inorder(root,order);
         TreeNode* first = NULL;
         TreeNode* second = NULL;
         for(int i=0;i<order.size()-1;i++){
            if(order[i]->val > order[i+1]->val){
                if(first == NULL)first = order[i];
                second = order[i+1];
            }
         }
         swap(first->val,second->val);
    }
};