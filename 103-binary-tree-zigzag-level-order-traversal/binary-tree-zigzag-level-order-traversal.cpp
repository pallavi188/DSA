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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
       queue<TreeNode*>q;
       vector<vector<int>>ans;
        if(root==NULL) return ans;
       bool leftToRight = true;
       q.push(root);
       while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            TreeNode* currNode = q.front();
            q.pop();
            if(currNode->left)q.push(currNode->left);
            if(currNode->right)q.push(currNode->right);
            level.push_back(currNode->val);
        }
        if(leftToRight){
            ans.push_back(level);
            leftToRight = false;
        }else{
            reverse(level.begin(),level.end());
            ans.push_back(level);
            leftToRight = true;
        }
       }
       return ans;
    }
};