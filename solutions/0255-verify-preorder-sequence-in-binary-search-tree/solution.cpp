class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size() <= 1) {
            return true;
        }
        /* if (preorder.size() == 2) {
            return (preorder[0] > preorder[1]);
        } */
        std::vector<int> inorder(preorder);
        std::sort(inorder.begin(), inorder.end());

        TreeNode* root = buildTree(preorder, inorder);
        // Verify if inorder traversal is "in order"

        return confirmBSTInorderTraversal(root);
    }
private:
    std::unordered_map<int, int> in_order_indices_;
    int preorder_index = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        constructInOrderMap(inorder);
        return buildTreeHelper(preorder, 0, (inorder.size() - 1));
    }
    void constructInOrderMap(vector<int>& inorder) {
        int index = 0;
        for (int& i: inorder) {
            in_order_indices_[i] = index;
            ++index;
        }
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, int l, int r) {
        // End case for recursion
        if (l > r || preorder_index > (preorder.size() - 1)) {
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
    bool confirmBSTInorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while ( !s.empty() || cur != nullptr)
        {
            if (cur!= nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            else {
                cur = s.top();
                s.pop();
                if ( prev && cur && prev->val >= cur->val )
                {
                    return false;
                }
                prev = cur;
                cur = cur->right;
            }
        }
        //std::cout << endl;
        return true;
    }
};
