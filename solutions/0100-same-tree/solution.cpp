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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if ((p == nullptr && q != nullptr) ||
            (p != nullptr && q == nullptr))
            return false;
        stack<TreeNode*> s;
        string psStr = "";
        string qsStr = "";
        queue<TreeNode*> nq;
        string pqStr = "";
        string qqStr = "";
        TreeNode *cur = p;
        while (cur != nullptr || !s.empty())
        {
            while(cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            psStr.append(to_string(cur->val));
            s.pop();
            cur = cur->right;
        }
        while (!s.empty())
        {
            s.pop();
        }
        cur = q;
        while (cur != nullptr || !s.empty())
        {
            while(cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            qsStr.append(to_string(cur->val));
            s.pop();
            cur = cur->right;
        }
        bool res1 = (psStr.compare(qsStr) == 0);
        cur = p;
        nq.push(cur);
        while(!nq.empty())
        {
            cur = nq.front();
            if (cur == nullptr)
            {
                pqStr.append("N");
                nq.pop();
                continue;
            }
            pqStr.append(to_string(cur->val));
            nq.pop();
            //if (cur->left != nullptr)
                nq.push(cur->left);
            //else
            //if (cur->right != nullptr)
                nq.push(cur->right);
        }
        cur = q;
        nq.push(cur);
        while(!nq.empty())
        {
            cur = nq.front();
            if (cur == nullptr)
            {
                qqStr.append("N");
                nq.pop();
                continue;
            }
            qqStr.append(to_string(cur->val));
            nq.pop();
            //if (cur->left != nullptr)
                nq.push(cur->left);
            //if (cur->right != nullptr)
                nq.push(cur->right);
        }
        cout << pqStr << " " << qqStr <<endl;
        bool res2 = (pqStr.compare(qqStr) == 0);
        
        return res1 && res2;
    }
};
