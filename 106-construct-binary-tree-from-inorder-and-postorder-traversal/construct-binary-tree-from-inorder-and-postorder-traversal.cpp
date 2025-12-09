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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size())
            return NULL;
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); ++i)
            mp[inorder[i]] = i;
        return helperTree(inorder, postorder, 0, inorder.size() - 1, 0,
                          postorder.size() - 1, mp);
    }

private:
    TreeNode* helperTree(vector<int>& inorder, vector<int>& postorder,
                         int inorderStart, int inorderEnd, int postorderStart,
                         int postorderEnd, unordered_map<int, int>& mp) {
        if (inorderStart > inorderEnd || postorderStart > postorderEnd) {
            return nullptr;
        }
        int rootval = postorder[postorderEnd];
        TreeNode* root = new TreeNode(rootval);
        int inorderRootIndex = mp[rootval];
        int leftSubtreeSize = inorderRootIndex - inorderStart;
        root->left = helperTree(inorder, postorder, inorderStart,
                                inorderRootIndex - 1, postorderStart,
                                postorderStart + leftSubtreeSize - 1, mp);
        root->right =
            helperTree(inorder, postorder, inorderRootIndex + 1, inorderEnd,
                       postorderStart + leftSubtreeSize, postorderEnd - 1, mp);
        return root;
    }
};