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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->right == nullptr && root->left == nullptr)
            return 1;
        stack<pair<int, TreeNode*>> s;
        TreeNode* cur = root;
        pair<int, TreeNode*> curStack;
        s.push(make_pair(1, cur));
        int maxDepth = INT_MIN;
        int depth = 1;
        while (!s.empty())
        {
            cur = s.top().second;
            depth = s.top().first;
            s.pop();
            if (depth > maxDepth)
                    maxDepth = depth;
            if (cur->right != nullptr)
            {
                s.push(make_pair(depth + 1, cur->right));
            }
            if (cur->left != nullptr)
            {
                s.push(make_pair(depth + 1, cur->left));
            }
            cout << maxDepth << endl;
        }
        return maxDepth;
    }
};
