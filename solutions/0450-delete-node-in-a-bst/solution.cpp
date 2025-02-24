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
    // FindKeyNode. Find the node with key. cur is expected to be initialized to root.
    TreeNode* FindKeyNode(TreeNode*& root, int& key, TreeNode*& prev) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->val < key) {
                prev = cur;
                cur = cur->right;
            } else if (cur->val > key) {
                prev = cur;
                cur = cur->left;
            }
            else if (cur->val == key) {
                return cur;
            }
            /*if (prev) {
                std::cout << "prev: " << prev->val << std::endl;
            }*/
        }
        return nullptr;
    }
    void DelLeafNode(TreeNode*& root, TreeNode*& del_node, TreeNode*& prev, bool& solved) {
        if (del_node->left || del_node->right) {
            return;
        }
        if (prev->left == del_node) {
            // std::cout << __FUNCTION__ << " " << __LINE__ << " " << prev->val << std::endl;
            prev->left = nullptr;
        }
        else {
            // std::cout << __FUNCTION__ << " " << __LINE__ << " " << prev->val << std::endl;
            prev->right = nullptr;
        }
        if (del_node == root) {
            root = nullptr;
        }
        solved = true;
        // delete del_node;
    }
    void DelNodeWithOneChild(TreeNode*& root, TreeNode*& del_node, TreeNode*& prev, bool& solved) {
        if (solved) {
            return;
        }
        TreeNode* left_single_child = (del_node->left != nullptr && del_node->right == nullptr)?del_node->left:nullptr;
        TreeNode* right_single_child = (del_node->left == nullptr && del_node->right != nullptr)?del_node->right:nullptr;
        if (left_single_child && right_single_child) {
            return;
        }
        if (!left_single_child && !right_single_child) {
            return;
        }
        // del_node == root
        if (del_node == root) {
            root = (left_single_child)?left_single_child:right_single_child;
            return;
        }
        if (prev->left == del_node) {
            if (left_single_child != nullptr)
                prev->left = left_single_child;
            else
                prev->left = right_single_child;
        } else if (prev->right == del_node) {
            if (left_single_child != nullptr)
                prev->right = left_single_child;
            else
                prev->right = right_single_child;                
        }
        // delete del_node;
        solved = true;
    }
    void DelNodeWithTwoChildren(TreeNode*& root, TreeNode*& del_node, TreeNode*& prev, bool& solved) {
        if (solved || !del_node->right || !del_node->left) {
            return;
        }
        // Find left-most child node (next_in_order) of right subtree
        TreeNode* next_in_order = del_node->right;// del_node is preserved for comparison.
        TreeNode* prev_next_in_order = nullptr;
        while (next_in_order->left) {
            prev_next_in_order = next_in_order;
            next_in_order = next_in_order->left;
        }
        // Depends on depth.
        // If we traversed to find the next_in_order.
        // The next_in_order's right child becomes Parent's left child
        if (prev_next_in_order) {
            prev_next_in_order->left = next_in_order->right;
        } else {
            del_node->right = next_in_order->right;
        }
        // Copy the "next in order" (left-most node of right subtree) value to del_node
        del_node->val = next_in_order->val;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if ((root->left == nullptr && root->right == nullptr) && root->val == key) {
            delete root;
            return nullptr;
        }
        else if ((root->left == nullptr && root->right == nullptr) && root->val != key)
        {
            return root;
        }
        // Find the node, of course
        TreeNode* prev = nullptr;
        bool solved = false;
        TreeNode* del_node = FindKeyNode(root, key, prev);
        if (del_node == nullptr)
            return root;
        // Case 1. Leaf
        DelLeafNode(root, del_node, prev, solved);
        // Case 2. Single Child.
        DelNodeWithOneChild(root, del_node, prev, solved);
        // Case 3. Two children
        DelNodeWithTwoChildren(root, del_node, prev, solved);
        return root;
    }
};
