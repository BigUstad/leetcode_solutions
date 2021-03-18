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
    void showContents(queue<TreeNode*> q)
    {
          while (!q.empty())
          {
            if (q.front() != nullptr)
            {
                cout << "   " << q.front()->val;
            }
            else
            {
                cout << "   " << "EndOfLevel";
            }
            q.pop();
          }
          std::cout << std::endl;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        vector<int> start;
        start.push_back(root->val);
        result.push_back(start);
        if (root->left != nullptr)
            q.push(root->left);
        if (root->right != nullptr)
            q.push(root->right);
        q.push(nullptr);
        vector<int> level;
        while (!q.empty())
        {
            TreeNode* front = q.front();
            if (front == nullptr)
            {
                if (level.size() > 0)
                    result.push_back(level);
                level.clear();
                if (q.size() != 1)
                    q.push(nullptr);
            }
            else
            {
                
                level.push_back(front->val);
                if (front->left != nullptr)
                    q.push(front->left);
                if (front->right != nullptr)
                    q.push(front->right);                
            }
            q.pop();
        }
        return result;
    }
};
