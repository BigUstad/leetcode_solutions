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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            result.push_back(root->val);
            return result;
        }
        stack<TreeNode*> s;
        TreeNode* cur = nullptr;
        s.push(root);
        while(!s.empty())
        {
            cur = s.top();
            s.pop();
            result.insert(result.begin(), cur->val);
            if (cur->left != nullptr)
            {
                s.push(cur->left);                
            }
            if (cur->right != nullptr)
            {
                s.push(cur->right);
            }
        }
        return result;
    }
};
