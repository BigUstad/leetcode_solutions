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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string l_ret;
        if (!root) {
            return l_ret;
        }
        std::queue<TreeNode*> q;
        TreeNode* cur = root;
        q.push(cur);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur->val == -1001) {
                l_ret.append(".L.");
                continue;
            } if (cur->val == 1001) {
                l_ret.append(".R.");
                continue;
            } else {
                l_ret.append(".");
                l_ret.append(std::to_string(cur->val));
                l_ret.append(".");
            }
            if (cur->left) {
                q.push(cur->left);
            } else {
                q.push(new TreeNode(-1001));
            }
            if (cur->right) {
                q.push(cur->right);
            } else {
                q.push(new TreeNode(1001));
            }
        }
        return l_ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        std::stringstream ss(data);
        std::string val;
        char delimiter = '.';
        TreeNode* root = nullptr;
        std::queue<TreeNode*> q;
        while(std::getline(ss, val, delimiter) && val.length() <= 0) ;
        root = new TreeNode(std::stoi(val));
        q.push(root);
        while (!q.empty()) {
            // Left child
            while(std::getline(ss, val, delimiter) && val.length() <= 0) ;
            TreeNode* prev = q.front(); q.pop();
            if (val == "L") {
                prev->left = nullptr;
            } else {
                prev->left = new TreeNode(std::stoi(val));
                q.push(prev->left);
            }

            // Right child
            while(std::getline(ss, val, delimiter) && val.length() <= 0) ;
            if (val == "R") {
                prev->right = nullptr;
            } else {
                prev->right = new TreeNode(std::stoi(val));
                q.push(prev->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
