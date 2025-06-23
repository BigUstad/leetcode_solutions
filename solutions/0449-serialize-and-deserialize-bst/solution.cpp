/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preOrderHelper(TreeNode* root, std::string& preorder) {
        std::stack<TreeNode*> s;
        // When nullptr is popped we are done.
        s.push(nullptr);
        while (root) {
            preorder.append(std::to_string(root->val));
            preorder.append(",");
            // It is a stack. The right node needs to be popped after the left.
            if (root->right) {
                s.push(root->right);
            }
            if (root->left) {
                root = root->left;
            } else {
                // So, done with the left subtree
                // Let's get the right node that has been pushed
                root = s.top(); s.pop();
            }
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        if (!root->left && !root->right) {
            return std::to_string(root->val);
        }
        std::string l_ret;
        preOrderHelper(root, l_ret);
        return l_ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() <= 0) {
            return nullptr;
        }
        TreeNode* root = nullptr;
        std::stringstream ss(data);
        std::vector<int> preorder;
        std::string val;
        const char delimiter(',');
        while(std::getline(ss, val, delimiter) && val.length() > 0) {
            preorder.push_back(std::stoi(val));
        }
        if (preorder.size() == 1) {
            return (new TreeNode(preorder[0]));
        }
        std::vector<int> inorder(preorder);
        std::sort(inorder.begin(), inorder.end());
        constructInorderMap(inorder);
        return buildTreeHelper(preorder, 0, (inorder.size() - 1));
    }
private:
    std::unordered_map<int, int> inorder_indices_;
    int preorder_index = 0;
    void constructInorderMap(std::vector<int>& inorder) {
        int idx = 0;
        for(int& i: inorder) {
            inorder_indices_[i] = idx;
            ++idx;
        }
    }
    TreeNode* buildTreeHelper(std::vector<int>& preorder, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int preorder_node_val = preorder[preorder_index++];
        TreeNode* cur = new TreeNode(preorder_node_val);
        cur->left = buildTreeHelper(preorder, l, (inorder_indices_[preorder_node_val] - 1));
        cur->right = buildTreeHelper(preorder, (inorder_indices_[preorder_node_val] + 1), r);
        return cur;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
