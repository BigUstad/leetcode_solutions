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
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* cur = head;
        std::stack<ListNode*, std::list<ListNode*>> s;
        while (cur) {
            s.push(cur);
            cur = cur->next;
        }
        int cur_max = s.top()->val;
        // ListNode* new_head = new ListNode(cur_max);
        ListNode* new_head = s.top();
        s.pop();
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            if (cur->val >= cur_max) {
                // ListNode* node = new ListNode(cur->val);
                cur->next = new_head;
                new_head = cur;
                cur_max = cur->val;
            }
        }
        return new_head;
    }
};
