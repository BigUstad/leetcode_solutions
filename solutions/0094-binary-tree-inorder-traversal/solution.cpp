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
    void inOrderHelper(TreeNode* root, list<int>& nums)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            nums.push_back(root->val);
            return;
        }
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
            nums.push_back(cur->val);
            cur = cur->right;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        list<int> result;
        inOrderHelper(root, result);
        return std::vector(result.begin(), result.end());
    }
};
