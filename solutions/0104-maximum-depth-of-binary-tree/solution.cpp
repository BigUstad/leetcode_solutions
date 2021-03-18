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
        queue<TreeNode*> q;
        int result = 0;
        if (root == nullptr)
            return result;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        result++;
        if (root->left != nullptr)
            q.push(root->left);
        if (root->right != nullptr)
            q.push(root->right);
        q.push(nullptr);
        while (!q.empty())
        {
            TreeNode* front = q.front();
            if (front == nullptr)
            {
                if (q.size() != 1)//Just the nullptr means it is empty
                {
                    q.push(nullptr);                    
                }
                result++;
            }
            else
            {
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
