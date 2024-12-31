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
    void inOrderHelper(TreeNode* root, std::vector<int>& nums, int& k)
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
    bool inorderTraversal(TreeNode* root, int& k) {
        std::vector<int> tree_list;

        inOrderHelper(root, tree_list, k);
        if (tree_list.size() <= 1) {
            return false;
        }
        int l = 0, r = tree_list.size() - 1;
        // Simulating BST
        while (l < r) {
            int sum = tree_list[l] + tree_list[r];
            // We're done
            if (sum == k) return true;
            // Warmer
            if (sum < k ) {
                l++;
            }// Colder
            else {
                r--;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        TreeNode* cur = root;
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return false;
        }
        return inorderTraversal(root, k);
    }
};
