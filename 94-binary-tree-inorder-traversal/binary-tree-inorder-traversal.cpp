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
    vector<int> inorderTraversal(TreeNode* root) {
          vector<int>inorder;
          TreeNode* curr = root;
          while(curr != NULL){
               if(curr->left == NULL){
                //case1 curr ka left null h 
                inorder.push_back(curr->val);
                curr = curr->right;
               }
               else{
                    //case2 curr=>left null nhi h 
                    TreeNode* prev = curr->left;
                    while(prev->right && prev->right != curr){
                        //right side me last node nhi h ye tho last find karo i.e inorder predecessor find krna h 
                        prev = prev->right;
                    }
                    if(prev->right == NULL){
                        //right side ka last node mil gya tho uska thread curr node se jod do 
                        prev->right = curr;
                        curr = curr->left;

                    }else{
                        prev->right = NULL;
                        inorder.push_back(curr->val);
                        curr = curr->right;
                    }
               }
          }
          return inorder;
    }
};