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
    bool isValidBST(TreeNode* root) {
        for (auto& l: resultList) {
            std::cout << l << "\t";
        }
        std::cout << std::endl;
        inOrderTraversal(root);
        for ( int i = 0;
                i < resultList.size();
                ++i ) {
            if ( i > 0 &&
                 resultList.at(i) < resultList.at(i - 1) ) {
                return false;
            }
            if ( (i+1) <= ( resultList.size() - 1 ) &&
                 resultList.at(i) >= resultList.at(i + 1) ) {
                return false;
            }
        }
        return true;
    }

    void inOrderTraversal(TreeNode* root) {
        if ( root == nullptr ) {
            return;
        }
        std::stack<TreeNode*> s;
        s.push(root);
        TreeNode* node(root->left);
        while ( !s.empty() || node != nullptr ) {
            while ( node != nullptr ) {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            // Process
            resultList.push_back(node->val);
            node = node->right;
        }
    }
private:
    std::vector<int> resultList;
};
