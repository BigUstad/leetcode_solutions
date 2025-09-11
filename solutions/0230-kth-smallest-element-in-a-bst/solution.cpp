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
    int kthSmallest(TreeNode* root, int k) {
        if (!root || k <= 0) {
            return -1;
        }
        if (!root->left && !root->right) {
            if (k == 1) return root->val;
            return -1;
        }
        return countNodes(root, k);
    }
private:
    int countNodes(TreeNode* current, int& k) {
        int count = 0;
        int k_min = -1;

        // std::cout << "Morris Path: ";
        while (current) {
            if (!current->left) {
                // Case 1: No left child.
                // Count the current node and move to the right.
                // count++;
                // std::cout << "  " << count << "." << current->val << " ? " << ((count == k)?"Yes":"No");
                if (++count == k) {
                    k_min = current->val;
                }
                current = current->right;
            } else {
                // Case 2: Left child exists.
                // Find the in-order predecessor of the current node.
                TreeNode* predecessor = current->left;
                while (predecessor->right && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if (!predecessor->right) {
                    // Threading phase: Link predecessor to current.
                    // Count the current node (pre-order).
                    // To do an in-order count, we would count here in this else block.
                    predecessor->right = current;
                    current = current->left;
                } else {
                    // Backtracking phase: Predecessor's right child is already current.
                    // This means the left subtree has been traversed.
                    // Count the current node (in-order).
                    // count++;
                    // std::cout << "  " << count << "." << current->val << " ? " << ((count == k)?"Yes":"No");
                    if (++count == k) {
                        k_min = current->val;
                    }
                    predecessor->right = nullptr; // Restore the tree
                    current = current->right;
                }
            }
        }
        // std::cout << std::endl;
        return k_min;
    }

    void inorderHelper(TreeNode* root, int& k, int& k_min) {
        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (!--k) {
                // kth popped element is the kth smallest value
                k_min = root->val;
                break;
            }
            root = root->right;
        }
    }
};
