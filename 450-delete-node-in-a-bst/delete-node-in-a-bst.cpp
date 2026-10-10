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
    TreeNode* deleteNode(TreeNode* root, int val) {
              if(!root)return root;
              if(root->val > val)root->left = deleteNode(root->left,val);
              else if(root->val < val)root->right = deleteNode(root->right,val);
              else{
                //root->val == val
                   if(root->left == NULL  && root->right == NULL){
                    //leaf node 
                    delete(root);
                    return NULL;
                   }//node to be f=deleted had one child
                   else if(root->left == NULL){
                      TreeNode* node = root->right;
                      delete(root);
                      return node;
                   }else if(root->right == NULL){
                    TreeNode* node = root->left;
                    delete(root);
                    return node;
                   }
                   else{
                    //node has two child then find its inorder predecessor and replace it the delete it
                    TreeNode* inorderP = root->left;
                    while(inorderP->right){
                        inorderP = inorderP->right;
                    }
                        root->val = inorderP->val;
                        root->left = deleteNode(root->left,inorderP->val);
                    
                   }
              }
              return root;
         }
    };