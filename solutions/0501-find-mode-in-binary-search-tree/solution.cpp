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

struct ValCount {
    int val;
    unsigned short count;
    explicit ValCount(int& _val) {
        val = _val;
        count = 1;
    }
};

class Solution {
public:
    void inOrderHelper(TreeNode* root, std::vector<ValCount>& vc) {
        std::stack<TreeNode*> s;
        s.push(root);
        TreeNode* cur = root->left;
        while (cur != nullptr || !s.empty()) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            // Process
            cur = s.top();
            s.pop();
            int vc_last = (int)(vc.size() - 1);
            if (vc_last >= 0 && vc[vc_last].val == cur->val) {
                vc[vc_last].count++;
            } else {
                vc.emplace_back(cur->val);
            }
            cur = cur->right;
        }
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> v_ret;
        if (root == nullptr) return v_ret;
        if (root->right == nullptr && root->left == nullptr) {
            v_ret.push_back(root->val);
            return v_ret;
        }
        unsigned short top_count = 0;
        std::vector<size_t> top_indices;
        std::vector<ValCount> vc;
        inOrderHelper(root, vc);
        for (auto& vce: vc) {
            if (vce.count > top_count) {
                top_count = vce.count;
            }
        }
        unsigned short index = 0;
        for (auto& vce: vc) {
            if (vce.count == top_count) {
                top_indices.push_back(index);
            }
            index++;
        }
        for (auto& ti: top_indices) {
            v_ret.push_back(vc[ti].val);
        }
        return v_ret;
    }
};
