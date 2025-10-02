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
class CBTInserter {
public:
    CBTInserter(TreeNode* _root) {
        if (!root) {
            return;
        }
        root = _root;
        std::queue<TreeNode*> v_q;
        v_q.push(root);
        while(!v_q.empty()) {
            TreeNode* cur = v_q.front(); v_q.pop();
            if (!cur->left || !cur->right) {
                q.push(cur);
            }
            if (cur->left) v_q.push(cur->left);
            if (cur->right) v_q.push(cur->right);
        }
    }
    
    int insert(int val) {
        TreeNode* cur = new TreeNode(val);
        q.push(cur);
        TreeNode* q_cur = q.front();
        if (!q_cur->left) {
            q_cur->left = cur;
            return q_cur->val;
        }
        q_cur->right = cur;
        q.pop();
        return q_cur->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
private:
    TreeNode* root;
    std::queue<TreeNode*> q;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
