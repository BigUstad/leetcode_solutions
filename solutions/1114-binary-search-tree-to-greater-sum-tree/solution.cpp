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
    TreeNode* bstToGst(TreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            return root;
        }
        std::vector<int> v_inorder;
        morrisTraversalBuilder(root, v_inorder);
        // Prefix Sum, but put it in a hashmap
        suffix_sum_map[v_inorder[v_inorder.size() - 1]] = v_inorder[v_inorder.size() - 1];
        int last = v_inorder[v_inorder.size() - 1];
        for (int index = (v_inorder.size() - 2); index >= 0; --index) {
            suffix_sum_map[v_inorder[index]] = last + v_inorder[index];
            last += v_inorder[index];
        }
        bfsHelper(root);
        return root;
    }
private:
    std::unordered_map<int, int> suffix_sum_map;
    void bfsHelper(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            cur->val = suffix_sum_map[cur->val];
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }    
    void morrisTraversalBuilder(TreeNode* root, std::vector<int>& result) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // If no left child visit this node & go right
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find the inorder predecessor of curr
                TreeNode* prev = curr->left;
                while (prev->right != nullptr &&
                    prev->right != curr) {
                    prev = prev->right;
                }
                // Make curr the right child of its inorder predecessor
                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // Revert the changes made in tree structure.
                    prev->right = nullptr;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }
};
