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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *newNode = new TreeNode(val);
        if (root == nullptr)
            return newNode;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (root->val > val)
            {
                root->left = newNode;
            }
            else
            {
                root->right = newNode;
            }
            return root;
        }
        TreeNode* prev = nullptr;
        TreeNode* cur = root;
        while (cur != nullptr)
        {
            prev = cur;
            cur = (cur->val < val)?cur->right:cur->left;
        }
        if (prev->val > val)
        {
            prev->left = newNode;
        }
        else
        {
            prev->right = newNode;
        }
        return root;
    }
};
