/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* bstHelper(vector<int>& nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int m = l + ((r - l) / 2);
        TreeNode* cur = new TreeNode(nums[m]);
        cur->left = bstHelper(nums, l, m - 1);
        cur->right = bstHelper(nums, m + 1, r);

        return cur;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return new TreeNode(head->val);
        }
        ListNode* cur = head;
        std::vector<int> nums;
        while (cur) {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        TreeNode* root = bstHelper(nums, 0, (nums.size() - 1));

        return root;
    }
};
