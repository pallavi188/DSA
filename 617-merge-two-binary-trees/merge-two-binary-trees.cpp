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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL)return root2;
        if(root2==NULL)return root1;
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root1,root2});
        while(!q.empty()){
            TreeNode* ptr1 = q.front().first;
            TreeNode* ptr2 = q.front().second;
            ptr1->val = (ptr1->val)+(ptr2->val);
            q.pop();
            if((ptr1->left)&&(ptr2->left))
            q.push({ptr1->left,ptr2->left});
            else if((!ptr1->left) && (ptr2->left))
            ptr1->left = ptr2->left;
            if((ptr1->right) &&(ptr2->right))
            q.push({ptr1->right,ptr2->right});
            else if((!ptr1->right) && (ptr2->right))
            ptr1->right = ptr2->right;
        }
        return root1;
    }
};