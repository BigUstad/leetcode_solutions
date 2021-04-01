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
    void inOrderHelper(TreeNode* root, vector<int>& nums)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            nums.push_back(root->val);
            return;
        }
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (!s.empty() || cur != nullptr)
        {
            //Left
            while(cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            // Process
            cur = s.top();
            s.pop();
            nums.push_back(cur->val);
            //Right
            cur = cur->right;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inOrderHelper(root, result);
        return result;
    }
};
