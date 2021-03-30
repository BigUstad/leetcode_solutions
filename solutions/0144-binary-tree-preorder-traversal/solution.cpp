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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> to_add;
        to_add.push(nullptr);
        if(!root) return ans;
        
        while(root) {
            ans.push_back(root->val);
            if(root->right) to_add.push(root->right);
            if(root->left) root = root->left;
            else {
                root = to_add.top();
                to_add.pop();
            }
        }
        return ans;
    }
};
