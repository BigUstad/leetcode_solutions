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
    std::string inorderHelper(TreeNode* root)
    {
        std::string s_ret;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* cur = root->left;
        while(cur != nullptr || !s.empty())
        {
            while(cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            // Process
            if (!cur->left && !cur->right) {
                s_ret.append(std::to_string(cur->val));
                s_ret.append(",");
            }
            cur = cur->right;
        }
        return s_ret;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        return  inorderHelper(root1) == inorderHelper(root2);
    }
};
