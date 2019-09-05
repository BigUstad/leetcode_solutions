/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* root)
    {
        if ( root == NULL )
            return 0;
        return (1 + std::max(getHeight(root->left),
                              getHeight(root->right)));
    }
    bool isBalanced(TreeNode* root) {
        int leftHeight, rightHeight;
        if ( root == NULL )
            return true;
        leftHeight = getHeight(root->left);
        rightHeight = getHeight(root->right);
        if ( abs(leftHeight - rightHeight ) <= 1
                && isBalanced(root->left)
                && isBalanced(root->right))
        {
            return true;
        }
        return false;
    }
};
