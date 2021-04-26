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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        if (root == nullptr)
            return -1;
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        dfsHelper(root, low, high, ans);
        return ans;
    }
    void dfsHelper(TreeNode* root, int low, int high, int& ans)
    {
        if (root == nullptr)
            return;
        if (root->val >= low && root->val <= high)
            ans += root->val;
        if (root->val > low)
            dfsHelper(root->left, low, high, ans);
        if (root->val < high)
            dfsHelper(root->right, low, high, ans);
    }
};
