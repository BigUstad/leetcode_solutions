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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        constructInOrderMap(inorder);
        return buildTreeHelper(preorder, 0, (inorder.size() - 1));
    }
private:
    std::unordered_map<int, int> in_order_indices_;
    int preorder_index = 0;
    void constructInOrderMap(vector<int>& inorder) {
        int index = 0;
        for (int& i: inorder) {
            in_order_indices_[i] = index;
            ++index;
        }
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, int l, int r) {
        // End case for recursion
        if (l > r) {
            return nullptr;
        }
        // Get the root element pre-order (root -> left -> right)
        // Find the root from inorder indices map
        // Every node after index 0 encountered in preorder is a root of a subtree. 
        //      Either it is a root node of a subtree
        //      Or it is a leaf node with no children
        int preorder_node_val = preorder[preorder_index++];
        TreeNode* root = new TreeNode(preorder_node_val);
        // For this root, recursively build its left subtree by taking the indices from inorder
        root->left = buildTreeHelper(preorder, l, in_order_indices_[preorder_node_val] - 1);
        // For this root, recursively build its right subtree by taking the indices from inorder
        root->right = buildTreeHelper(preorder, in_order_indices_[preorder_node_val] + 1, r);
        return root;
    }
};
